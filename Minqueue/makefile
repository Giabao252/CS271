driver: main.o test_minqueue.o
	g++ -o test test_minqueue.o
	g++ -o usecase main.o

main.o: main.cpp usecase.cpp minqueue.cpp minqueue.h
	g++ -c main.cpp

test_minqueue.o: minqueue.cpp minqueue.h test_minqueue.cpp
	g++ -c test_minqueue.cpp