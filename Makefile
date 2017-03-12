
OBJECTS := Gene.o Genome.o Individual.o Population.o Timer.o main.o
CXXFLAGS ?= -g -std=c++11

.PHONY: all clean

all: universe
	
clean:
	rm -rf universe $(OBJECTS)
	
universe: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ -c $^

