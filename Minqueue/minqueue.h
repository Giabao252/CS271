//========================================================
// Linh Mai, Bao Luu, Jeremiah Shelton
// CS271, Fall 2023
// minqueue.h
// This file contains the MinQueue class declaration.
//========================================================

#include <iostream>
#include <string>
using namespace std;

#define DEFAULT_LIST_CAPACITY 10

template <class T>

class MinQueue
{
private:
    T* HeapArray; //the heap array
    int array_size;
    int heap_size;
    int PARENT(int i);
    int LEFT(int i);
    int RIGHT(int i);
    void SWAP(int index1, int index2);

public:
    MinQueue(void);
    MinQueue(T *A, int n);
    ~MinQueue(void);

    // Priority Queue Methods
    T min() const;
    T extract_min(void);
    void insert(T x);
    void decrease_key(int i, T k);

    // Heap Methods
    void min_heapify(int i);
    void build_heap();
    void sort(T *A);

    // Test-driven methods
    string to_string(void);
    void set(int i, T val);
    void allocate(int n);
};