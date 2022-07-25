app: main.o transition.o graph.o
	g++ -o dist/app -std=c++17  -Wall obj/main.o obj/Transition.o obj/Graph.o

main.o: main.cpp
	g++ -c -Wall main.cpp -I inc/ -o obj/main.o

transition.o: lib/Transition.cpp
	g++ -c -Wall lib/Transition.cpp -I inc/ -o obj/Transition.o

graph.o: lib/Graph.cpp
	g++ -c -Wall lib/Graph.cpp -I inc/ -o obj/Graph.o