
#include "Gene.hpp"

#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cassert>

Gene::Gene(){
	id = 0;
	std::fill_n(alleles_, 2, 0);
}

void Gene::setAlleles(int left, int right){
	if( left < right )
		std::swap(left, right);
	
	alleles_[0] = left;
	alleles_[1] = right;
}

void Gene::sortAlleles(){
	if( alleles_[0] < alleles_[1] )
		std::swap(alleles_[0], alleles_[1]);
}

Gene Gene::createByCombining(Gene a, Gene b){
	// First a little sanity check: make sure the genes we're trying to
	// combine are the same type.
	assert(a.id == b.id);
	
	// Create the new gene
	Gene result;
	result.id = a.id;
	result.type = a.type;
	
	// Decide at random which allele we take from each parent
	int alleleFromA, alleleFromB;
	alleleFromA = rand() % 2;
	alleleFromB = rand() % 2;
	result.setAlleles(a.alleles_[alleleFromA], b.alleles_[alleleFromB]);
	
	return result;
}
