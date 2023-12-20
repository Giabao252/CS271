test: test_graph.o
	g++ -std=c++11 -o test test_graph.o
	
test_graph.o: graph.h graph.cpp test_graph.cpp 
	g++ -std=c++11 -c test_graph.cpp
	
clean:
	rm -f *.o test