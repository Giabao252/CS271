#include <iostream>
#include <string>
#include "element.h"

using namespace std;
#define DEFAULT_ARRAY_CAPACITY 10

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class T>
class HashTable {
    public:
        
                HashTable       (void);
                HashTable       (int s);
                ~HashTable      (void);
        void    insert          (const T data, const int key);
        void    remove          (int key);
        bool    member          (const T data, const int key) const;
        int     hash_func       (int k) const;
        string  to_string       (void) const;
        int     size;

    private:
        struct Elem {
            Element<T> node;
            Elem *next;
            Elem *prev;
        };
        Elem **table;
};

#endif