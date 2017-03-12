
#include "Genome.hpp"
#include "Individual.hpp"
#include "Timer.hpp"
#include "Gene.hpp"
#include "Population.hpp"

#include <cstdio>
#include <cstdlib>

static const char GENOME_FILE_PATH[] = "genes.json";
static const char OUTPUT_FILE_PATH[] = "population.json";
static const uint64_t POPULATION_SIZE = 50000;

int main(int argc, char **argv){
	srand((unsigned int) time(nullptr));
	
	Timer timer;
	Population population;
	
	// 1. Load the genome
	std::printf("Loading genome from '%s'...\n", GENOME_FILE_PATH);
	timer.start();
	
	if( ! population.loadGenomeFromFile(GENOME_FILE_PATH) ){
		std::fprintf(stderr, "Failed to load genome from '%s' :(\n", GENOME_FILE_PATH);
		return EXIT_FAILURE;
	}
	
	std::printf("> Loaded %lu genes from '%s' in %fs\n",
				population.genome().geneCount(), 
				GENOME_FILE_PATH,
				timer.currentTime());
	
	// 2. Generate the population
	std::printf("Generating %llu random individuals...\n", 
				POPULATION_SIZE);
	
	timer.start();
	population.generateRandom(POPULATION_SIZE);
	
	std::printf("> Generated %lu individuals in %fs\n", 
				population.size(), timer.currentTime());
	
	float malePercent, femalePercent;
	population.genderProportions(malePercent, femalePercent);
	std::printf("> Gender proportions: male:%.2f%% female: %.2f%%\n",
				malePercent * 100.0f, femalePercent * 100.0f);
	
	// 3. Write that population to a file
	std::printf("Writing %lu individuals to '%s'\n", 
				population.size(), OUTPUT_FILE_PATH);
	
	timer.start();
	population.writeIndividualsToFile(OUTPUT_FILE_PATH);
	
	std::printf("> Wrote %lu individuals in %fs\n",
				population.size(), timer.currentTime());
	
	return 0;
}

