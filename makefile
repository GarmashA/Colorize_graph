output: main.o Colorize.o Graph.o
	g++ main.o Colorize.o Graph.o -o output

main.o: main.cpp
	g++ -c -std=c++17 main.cpp

Colorize.o: Colorize.cpp
	g++ -c -std=c++17 Colorize.cpp

Graph.o: Graph.cpp
	g++ -c -std=c++17 Graph.cpp

clean:
	rm *.o output

