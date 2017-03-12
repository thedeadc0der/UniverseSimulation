#ifndef Individual_hpp
#define Individual_hpp

#include "Gene.hpp"
#include "Genome.hpp"
#include <vector>

enum class Gender {
	Female	= 0,
	Male	= 1,
};

class Individual {
	std::vector<Gene> genes_;
	std::vector<Individual*> children_;
	
public:
	Individual *mother, *father;
	
public:
	Individual();
	
	size_t geneCount() const;
	const Gene& geneAt(size_t i) const;
	bool isChildOf(Individual *i) const;
	
	void addGene(Gene g);
	
	Gender gender() const;
	
public:
	static Individual createByReproducing(Individual& a, Individual& b);
	static Individual createRandom(const Genome& g);
};

inline size_t Individual::geneCount() const {
	return genes_.size();
}

inline const Gene& Individual::geneAt(size_t i) const {
	return genes_[i];
}

inline void Individual::addGene(Gene g){
	genes_.push_back(g);
}


#endif /* Individual_hpp */
