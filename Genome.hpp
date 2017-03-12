#ifndef Genome_hpp
#define Genome_hpp

#include <string>
#include <vector>

struct GeneType {
	int					id;
	std::string			name;
	std::vector<int>	alleles;
	
	GeneType(){
		id = 0;
	}
	
public:
	size_t alleleCount() const;
	int alleleAt(size_t i) const;
	int randomAllele() const;
};

inline size_t GeneType::alleleCount() const {
	return alleles.size();
}

inline int GeneType::alleleAt(size_t i) const {
	return alleles[i];
}

class Genome {
	std::vector<GeneType> geneTypes_;
	
public:
	Genome();
	
	size_t geneCount() const;
	const GeneType& geneAt(size_t i) const;
	void clear();
	
public:
	bool loadFromFile(const char *path);
};

inline void Genome::clear(){
	geneTypes_.clear();
}

#endif /* Genome_hpp */
