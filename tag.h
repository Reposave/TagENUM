#include <string>

#ifndef _TAG
#define _TAG

namespace DLMARD001{
	struct TagStruct{
		std::string tagName;
		int NumOfTagPairs;
		std::string text;
			};
		}

namespace DLMARD001{
	void ReadAndParse(std::string fileName);
}        

#endif

