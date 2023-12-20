#include <iostream>
#include <string>
#include <sstream>
#include "../header/element.h"

using namespace std;


// --------------------------------------------------------------------------------------------------------
// CONSTRUCTOR & DESTRUCTOR
// --------------------------------------------------------------------------------------------------------
template <class T>
Element<T>:: Element(void) {
    key = -1; //key is initialized to -1 by default (empty slot)
    // data = 0;
}

template <class T>
Element<T>:: Element(T data, int key) {
    this->key = key; //setting the key of the Element object to the passed key parameter
    this->data = data; //setting the data value of the Element objet to the passed data parameter
}

// --------------------------------------------------------------------------------------------------------
// get_key()
//  post-condition: Returns the numeric key value of the element.
//  parameters: none
//  return type: int
// --------------------------------------------------------------------------------------------------------
template <class T>
int Element<T>::get_key (void) const{
    return key; //return the key of the element object
}

// --------------------------------------------------------------------------------------------------------
// get_data()
//  post-condition: Returns the template data of the element.
//  parameters: none
//  return type: T
// --------------------------------------------------------------------------------------------------------
template <class T>
T Element<T>::get_data (void) const{
    return data; //return the data value of the element object
}