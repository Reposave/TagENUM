#include "tag.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

std::vector<DLMARD001::TagStruct> Tags;

void DLMARD001::ReadAndParse(std::string fileName){
	std::ifstream in(fileName);
	std::string line;
	std::string all_words; //Stores all text found in the file.

	if(!in)
        {
                std::cout << "Couldn't open file " << fileName << std::endl;
               
        }
	
	std::stack <DLMARD001::TempStruct> s;
	int globalposition = 0; //used to calculate the appropriate position of Tags after all_words has been emptied.
	
	while (std::getline(in, line)){
		
		globalposition = all_words.length();
		all_words = all_words + line;
		
		int tag_open = line.find('<');

		while(tag_open!=std::string::npos){ //If '<' has not been found.
		
		//std::cout << all_words << std::endl;
		
		//std::cout << tag_open << std::endl;
		
		if(line.at(tag_open+1)!='/'){
			int tag_close = line.find('>');
			
            std::string close_tag = line.substr (tag_open+1,tag_close-(tag_open+1));
			
			line.replace(tag_open,1,"*"); //removing "<"
			line.replace(tag_close,1,"*"); //removing ">"
			
			tag_open = tag_open + globalposition;

			s.push({close_tag,tag_open});
		}
		else{
			int tag_cloze = 0;
			
			tag_cloze = line.find('>');
			
			std::string cloze_tag = line.substr (tag_open+2,(tag_cloze-(tag_open+2)));
			
			line.replace(tag_open,1,"*"); //removing "<"
			line.replace(tag_cloze,1,"*"); //removing ">"
			
			tag_open = tag_open + globalposition;
			tag_cloze = tag_cloze + globalposition;	
			
			if(s.top().tagName == cloze_tag){
			bool found = false;
			
				int textstart = s.top().position+cloze_tag.length()+2; //The start of text after the opening tag.
				
				for (auto& it : Tags){
					
					if(it.tagName == cloze_tag){
						found = true;
						it.NumOfTagPairs = it.NumOfTagPairs + 1;
						
						it.text = it.text + ":" + all_words.substr(textstart, tag_open-textstart);
						break;
					}
				}
				if(!found){
                                                Tags.push_back({s.top().tagName,1, all_words.substr(textstart,tag_open-textstart)});
                                        } 
                    all_words.replace(s.top().position,((tag_cloze+1)-s.top().position),"");
					s.pop();

			}

		}
		tag_open = line.find('<'); //First start by finding the first opening tag.
	}
}

	in.close();
}
void DLMARD001::PrintTags(void){
	for (auto& its : Tags) {

                std::cout << "\"" + its.tagName +"\"" << "," << its.NumOfTagPairs <<  "," << "\"" + its.text + "\"" << std::endl;
        }

}
void DLMARD001::DWrite(void){
	std::ofstream out ("tags.txt");
		for (auto& its : Tags) {

                out << "\"" + its.tagName +"\"" << "," << its.NumOfTagPairs <<  "," << "\"" + its.text + "\"" << std::endl;
        }
       out.close();
}
void DLMARD001::List(std::string tag){
		
		for (auto& its : Tags){
					
					if(its.tagName == tag){
						std::cout << "\"" + its.tagName +"\"" << "," << its.NumOfTagPairs <<  "," << "\"" + its.text + "\"" << std::endl;
						break;
					}
	
}
}
