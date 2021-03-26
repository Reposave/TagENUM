#How to Run

In the terminal, type 'make' to compile.

'make clean' to remove binary files.

to run, type the following:

```bash
./tagENUM.exe
```
A Menu will appear with several commands.

#Put txt files in the Data folder in order to read them. Dumping/writing will place output results "tags.txt" in the Data folder.

tag.h is the header file which contains the declarations for methods and structs needed by tags.cpp

tag.cpp contains the definitions for the methods declared in the header file. All commands input in the command loop menu are evaluated in tag.cpp

tagDriver.cpp only contains the console interface for the menu and invokes functions found in tag.cpp.

.gitignore excludes binary files from the repository.