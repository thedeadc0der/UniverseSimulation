
#include "Population.hpp"

#include "json.hpp"
using json = nlohmann::json;

#include <fstream>
#include <iostream>

Population::Population(){
}

bool Population::loadGenomeFromFile(const char *path){
	genome_.clear();
	return genome_.loadFromFile(path);
}

static json geneToJSON(const Gene& g){
	json alleles;
	alleles[0] = g.alleleL();
	alleles[1] = g.alleleR();
	
	json result;
	result["id"] = g.id;
	result["type"] = g.type;
	result["alleles"] = alleles;
	
	return result;
}

static json individualToJSON(const Individual& ind){
	json genes;
	
	for(size_t i=0; i < ind.geneCount(); ++i)
		genes.push_back(geneToJSON(ind.geneAt(i)));
	
	json result;
	result["genes"] = genes;
	return result;
}

bool Population::writeIndividualsToFile(const char *path){
	std::ofstream file;
	file.open(path);
	
	if( ! file.is_open() )
		return false;
	
	json jsonArray;
	
	for(Individual& curr: individuals_)
		jsonArray.push_back(individualToJSON(curr));
	
	file << jsonArray;
	return true;
}

void Population::generateRandom(unsigned long long count){
	individuals_.clear();
	
	for(size_t i=0; i < count; ++i)
		individuals_.push_back(Individual::createRandom(genome_));
}

void Population::genderProportions(float &maleProp, float &femaleProp) const {
	unsigned long maleCount=0, femaleCount=0;
	
	for(const Individual& curr: individuals_){
		assert(curr.gender() == Gender::Female || curr.gender() == Gender::Male);
		
		if( curr.gender() == Gender::Female )
			femaleCount++;
		else
			maleCount++;
	}
	
	  maleProp = float(  maleCount) / float(individuals_.size());
	femaleProp = float(femaleCount) / float(individuals_.size());
}

