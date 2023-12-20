all: test usecase

test: test_bst.o bst.o
	g++ -otest $^

usecase: main.o usecase.o bst.o
	g++ -o usecase $^

main.o: main.cpp usecase.cpp bst.h bst.cpp
	g++ -c $<

bst.o: bst.cpp bst.h
	g++ -c $<

test_bst.o: test_bst.cpp bst.h bst.cpp
	g++ -c -w $<

usecase.o: usecase.cpp
	g++ -c $<

clean:
	rm -f *.o test usecase