SOURCES := graph.cpp main.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


all: comp run
comp:$(OBJECTS)
	@clear 
	@g++ $(OBJECTS) -o smd

graph.o:
	@g++ -c graph.cpp -o graph.o -std=c++11

main.o:
	@g++ -c main.cpp -o main.o -std=c++11

graph.dep:
	@g++ -c -MM graph.cpp -MT "graph.dep graph.o" -o graph.dep  -std=c++11

main.dep:
	@g++ -c -MM main.cpp -MT "main.dep main.o" -o main.dep -std=c++11
-include graph.dep main.dep  -std=c++11
 
run:
	@./smd
	@ctags -R .
clean:
	rm smd *.o *.dep tags
