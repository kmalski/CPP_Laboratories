OUTPUT=atest

CXX=g++
CXXFLAGS=-Wall -g 

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $@
	
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f $(OUTPUT) $(OBJ)
	
run:
	@./$(OUTPUT)
	
check:
	@valgrind ./$(OUTPUT)

.PHONY: all clean run check	
	
