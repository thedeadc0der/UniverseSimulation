#ifndef Gene_hpp
#define Gene_hpp

#include <string>

class Gene {
	int			alleles_[2];
	
public:
	int			id;
	std::string	type;
	
public:
	Gene();
	
public:
	int alleleL() const;
	int alleleR() const;
	int speakingAllele() const;
	
	void setAlleleL(int v);
	void setAlleleR(int v);
	void setAlleles(int left, int right);
	
	void sortAlleles();
	
public:
	static Gene createByCombining(Gene a, Gene b);
};

inline int Gene::alleleL() const {
	return alleles_[0];
}

inline int Gene::alleleR() const {
	return alleles_[1];
}

inline void Gene::setAlleleL(int v){
	alleles_[0] = v;
}

inline void Gene::setAlleleR(int v){
	alleles_[1] = v;
}

inline int Gene::speakingAllele() const {
	return alleles_[0];
}

#endif /* Gene_hpp */
