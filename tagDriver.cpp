#include "tag.h"
#include <cstdlib> 
#include <iostream>
#include <string>

int main (void)
{
	std::string userIn;

	for(;;){
		std::cout << "Tag Enumeration Program.\nThis program will search for tags in an input file.\nCommand List\n";
		std::cout << "r: Read and process tag file\np: Print all tags\nd: dump/write tags and data to a file called tag.txt\nl: list data for a given tag to cout\nq: quit program\n";
		
		std::cin >> userIn;
		std::cout << std::endl;

	if(userIn=="r" or userIn=="R"){
		std::cout << "Enter filename..." << std::endl;
		std::cin >> userIn;
		
		DLMARD001::ReadAndParse(userIn);
		std::cout << "File read!\n";
	}
	else if(userIn=="p" or userIn=="P"){
		std::cout << "Printing tags..." << std::endl;
		DLMARD001::PrintTags();
	}
	else if(userIn=="d" or userIn=="D"){
		std::cout << "writing to tags.txt in Data folder..." << std::endl;
		DLMARD001::DWrite();
	}
	else if(userIn=="l" or userIn=="L"){
		std::cout << "Enter name of Tag..." << std::endl;
		std::cin >> userIn;
		
		DLMARD001::List(userIn);
	}
	else if(userIn=="q" or userIn=="Q"){
		std::cout << "Goodbye" << std::endl;
		break;
	}
	else{
		std::cout << "invalid command." << std::endl;
	}
	
	std::cout << "Press any key then Enter to continue" << std::endl;
	std::cin >> userIn;

	system("clear");
	}
	return 0;
}
