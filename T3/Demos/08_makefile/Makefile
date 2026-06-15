# Topic: Makefile
# Q8.1: touch vec.h (add a blank line), save, run `make` -- what happens?
# Q8.2: if a recipe line is indented with spaces instead of a TAB, what does `make`
#       print? (see Makefile.broken)

CXX = g++                              # which compiler to use
CXXFLAGS = -std=c++17 -Wall -g -MMD    # -MMD auto-generates .d dependency files
EXEC = vecdemo
CCFILES = $(wildcard *.cc)             # every .cc file in this directory
OBJECTS = ${CCFILES:.cc=.o}            # same names, .cc -> .o
DEPENDS = ${CCFILES:.cc=.d}            # same names, .cc -> .d

${EXEC}: ${OBJECTS}                     # the executable depends on all the .o files
	${CXX} ${OBJECTS} -o ${EXEC}        # recipe (TAB-indented): link them

-include ${DEPENDS}                     # pull in the auto-generated dependency rules

.PHONY: clean
clean:
	rm -f ${EXEC} ${OBJECTS} ${DEPENDS}


