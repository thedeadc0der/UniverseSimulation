#ifndef Population_hpp
#define Population_hpp

#include "Genome.hpp"
#include "Individual.hpp"

#include <vector>

class Population {
	Genome genome_;
	std::vector<Individual> individuals_;
	
public:
	Population();
	
	bool loadGenomeFromFile(const char *path);
	bool writeIndividualsToFile(const char *path);
	
	void generateRandom(unsigned long long count);
	
public:
	const Genome& genome() const;
	Genome& genome();
	size_t size() const;
	Individual& individualAt(size_t i);
	void clear();
	
	void genderProportions(float& malePercent, float& femalePercent) const;
};

inline const Genome& Population::genome() const {
	return genome_;
}

inline Genome& Population::genome() {
	return genome_;
}

inline size_t Population::size() const {
	return individuals_.size();
}

inline Individual& Population::individualAt(size_t i){
	return individuals_[i];
}

inline void Population::clear(){
	individuals_.clear();
}

#endif /* Population_hpp */
