
#include "Individual.hpp"

#include <cassert>

Individual::Individual(){
	mother = father = nullptr;
}

Gender Individual::gender() const {
	// Retrieve our gender gene, and make sure it is valid.
	int allele23 = genes_[0].speakingAllele();
	assert(allele23 == 0 || allele23 == 1);
	
	if( allele23 == 1 )
		return Gender::Male;
	else
		return Gender::Female;
}

bool Individual::isChildOf(Individual *i) const {
	assert(i != nullptr);
	
	return ( i == mother || i == father );
}

Individual Individual::createByReproducing(Individual &a, Individual &b){
	// First, some sanity checks. Namely,
	//  - Ensure both individuals aren't the same gender
	//  - Ensure they have the same number of genes
	assert(a.gender() != b.gender());
	assert(a.geneCount() == b.geneCount());
	
	Individual newBorn;
	
	// Assign the parents
	if( a.gender() == Gender::Female ){
		newBorn.mother = &a;
		newBorn.father = &b;
	} else {
		newBorn.mother = &b;
		newBorn.father = &a;
	}
	
	// And now create its genome by combining genes from the parents
	for(size_t i=0; i < a.geneCount(); ++i){
		Gene childGene = Gene::createByCombining(a.geneAt(i), b.geneAt(i));
		newBorn.addGene(childGene);
	}
	
	return newBorn;
}

Individual Individual::createRandom(const Genome &g){
	Individual result;
	
	// Add a random allele combination for each gene
	for(size_t i=0; i < g.geneCount(); ++i){
		Gene gene;
		gene.id = g.geneAt(i).id;
		gene.type = g.geneAt(i).name;
		
		int alleleA, alleleB;
		alleleA = g.geneAt(i).randomAllele();
		alleleB = g.geneAt(i).randomAllele();
		gene.setAlleles(alleleA, alleleB);
		
		result.addGene(gene);
	}
	
	return result;
}

