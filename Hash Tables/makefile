GCC = g++ -std=c++11
PROGS = testing

all: $(PROGS) clean

testing: test_hashtable.o main.o
	$(GCC) test_hashtable.o -o test
	$(GCC) main.o -o usecase
	
test_hashtable.o: cpp/test_hashtable.cpp cpp/element.cpp header/element.h cpp/hash_table.cpp header/hash_table.h cpp/usecase.cpp header/usecase.h
	$(GCC) -c cpp/test_hashtable.cpp

main.o: cpp/main.cpp cpp/element.cpp header/element.h cpp/hash_table.cpp header/hash_table.h cpp/usecase.cpp header/usecase.h
	$(GCC) -c cpp/main.cpp

clean:
	rm -f *.o testing