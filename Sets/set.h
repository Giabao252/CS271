//========================================================
// Linh Mai, Bao Luu, Jeremiah Shelton
// CS271, Fall 2023
// set.h
// This file contains the Set class declaration.  
//========================================================
#include <iostream>
#include <string>
using namespace std;


#define DEFAULT_SET_CAPACITY 20

template <class T>
class Set
{
private:
    
    struct Node
    {
        T item;
        Node *next;
    };

    Node *head; 

public:
    Set (void);
    Set (const Set<T> &otherSet);
    ~Set (void);
    void insert(T x);
    void remove(T x);
    int cardinality(void) const;
    bool empty(void) const;
    bool contains(T x) const;
    string to_string(void) const;
    bool operator==(const Set<T> &t) const;
    bool operator<=(const Set<T> &t) const;
    Set<T> operator+(const Set<T> &t) const;
    Set<T> operator&(const Set<T> &t) const;
    Set<T> operator-(const Set<T> &t) const;
};
