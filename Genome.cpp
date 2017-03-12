
#include "Genome.hpp"

#include "json.hpp"
using json = nlohmann::json;

#include <fstream>

int GeneType::randomAllele() const {
	int index = rand() % alleles.size();
	return alleles[index];
}

Genome::Genome(){
}

size_t Genome::geneCount() const{
	return geneTypes_.size();
}

const GeneType& Genome::geneAt(size_t i) const {
	return geneTypes_[i];
}

// Loading from a JSON file
static std::vector<int> readAlleleList(json& j){
	std::vector<int> result;
	
	for(size_t i=0; i < j.size(); ++i)
		result.push_back( j[i] );
	
	return result;
}

bool Genome::loadFromFile(const char *path){
	// Open the file
	std::ifstream file;
	file.open("genes.json");
	
	if( ! file.is_open() )
		return false;
	
	// Read its contents as JSON
	json jsonArray;
	file >> jsonArray;
	
	// The JSON file should be a big array of genes.
	// Make sure that's the case
	if( ! jsonArray.is_array() ){
		std::cerr << "JSON file '" << path << "' is invalid" << std::endl;
		return false;
	}
	
	// Now, read each of these gene types and add them to the list
	for(size_t i=0; i < jsonArray.size(); ++i){
		GeneType type;
		
		type.id      = jsonArray[i]["type-id"];
		type.name    = jsonArray[i]["type-string"];
		type.alleles = readAlleleList(jsonArray[i]["values"]);
		
		geneTypes_.push_back(type);
	}
	
	return true;
}

