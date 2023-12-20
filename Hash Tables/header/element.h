#include <iostream>
#include <string>

using namespace std;

#ifndef ELEMENT_H
#define ELEMENT_H

template <class T>
class Element
{
public:
    Element(void);
    Element(T data, int key);

    int get_key(void) const;
    T get_data(void) const;

    private:
        T data{};
        int key;

        
};

#endif