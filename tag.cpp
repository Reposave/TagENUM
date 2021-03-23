#include "tag.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<DLMARD001::TagStruct> Tags;

void DLMARD001::ReadAndParse(std::string fileName){
	std::ifstream in("Data/"+fileName);
	std::string s;
	while (std::getline(in, s)){

	std::cout << s << std::endl;

	}

	 
}
