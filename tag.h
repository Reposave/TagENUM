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
	struct TempStruct{ //Used temporarily to store index positions of tags for string slicing.
		std::string tagName;
		int position;
		};
}

namespace DLMARD001{
	void ReadAndParse(std::string fileName);
	void PrintTags(void);
	void DWrite(void);
	void List(std::string tag);
}        

#endif

