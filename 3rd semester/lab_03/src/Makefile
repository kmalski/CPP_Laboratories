OUTPUT=pesel_test

CXX=g++
CXXFLAGS=-Wall -g -c

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(OBJ) -o $@
	
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f $(OUTPUT) $(OBJ)
	
run:
	@./$(OUTPUT)
	
check:
	@valgrind ./$(OUTPUT)

.PHONY: all clean run check 	
	
