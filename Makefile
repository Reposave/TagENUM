# This is a Makefile comment
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref

# Need object files tag.o and tagDriver.o to create exe tagENUM 
tagDriver: tag.o tagDriver.o
	$(CC) tag.o tagDriver.o -o tagENUM.exe $(LIBS)

# Implicit pattern rule for compiling object files
%.o : %.cpp   # $< is the first dependancy and $@ is the target
	$(CC) -c $< -o $@
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
	@rm tagENUM
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
  
	@mv tagENUM ~/bin
