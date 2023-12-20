#include <iostream>
#include <string>
#include <sstream>
#include "../header/hash_table.h"


using namespace std;


// --------------------------------------------------------------------------------------------------------
// CONSTRUCTORS & DESTRUCTOR
// --------------------------------------------------------------------------------------------------------
template <class T>
HashTable<T>:: HashTable(void) {
    size = DEFAULT_ARRAY_CAPACITY; //initializing the size of the hash table to a default value of 10

    //Create a dynamic array of Element<T>* pointers, representing the hash table.
    table = new Elem *[size]; //the hash table is empty and all slots points to null

}

template <class T>
HashTable<T>:: HashTable(int s) {
    size = s; // set the size of the hash table 
    table = new Elem*[size]; //allocate memory for an array with s slots

    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}


template <class T>
HashTable<T>:: ~HashTable(void) {
    //Iterate through each slot in the hash table
    for (int i = 0; i < size; i++) {
        //Create a pointer to the first element in the current slot
        Elem *iter = table[i];
        //Traverse the linked list in the current slot
        while (iter) {
            //Update the current slot to point to the next element in the list
            table[i] = iter->next;
            //Delete the current element, freeing its memory
            delete iter;
            //Move the iterator to the next element in the list
            iter = table[i];
        }
    }
    delete[] table; //Delete the hash table itself
}


// --------------------------------------------------------------------------------------------------------
// hash_func()
//  pre-condition: The hashed key must be a positive integer or within the table size.  
//  post-condition: Returns the index of the hash table where the element with the given key is located.
//  parameters: k - The key we need to determine its slot in the hash table.
//  return type: int
// --------------------------------------------------------------------------------------------------------

template <class T>
int HashTable<T>::hash_func(int k) const {
    //Check if the size of the hash table is zero
    if (size == 0) {
        return 0; //If yes, return 0 as a default index (avoid division by zero)
    }
    return k%size; //Else, calculate the table index by taking the remainder of the key when divided by the table size
}


// --------------------------------------------------------------------------------------------------------
// to_string()
//  pre-condition: The hash table must not be empty.
//  post-condition: Returns a string representation of the hash table.
//  parameters: none
//  return type: a string with the elements in each doubly linked list separated by a single space and displayed as (data, key).
// --------------------------------------------------------------------------------------------------------

template <class T>
string HashTable<T>:: to_string(void) const {
    // Check if the hash table is empty. If it is, return an empty string
    if (size == 0) {
        return "";
    }

    stringstream stream; // Create a stringstream to build the string representation
    // Iterate over each slot (index) in the hash table
    for (int i = 0; i < size; i++ ) {
        stream << i << ": "; // Print the slot index

        Elem *ptr = table[i];
        // Check if the slot is empty. If it is, print a newline and continue
        if (ptr == NULL) {
            stream << "\n";
            continue;
        }
        // Iterate over the elements in the linked list at the current slot
        while (ptr->next != NULL) {
            // Append the element's data and key in the format (data, key) to the string
            stream << "(" << ptr->node.get_data() << "," << ptr->node.get_key() << ") ";
            ptr = ptr->next;
        }
        //Print the last element in the linked list at the current slot
        stream << "(" << ptr->node.get_data() << "," << ptr->node.get_key() << ") ";
        //Add a newline to separate slots
        stream << "\n";
    }

    //Convert the stringstream to a string and return it as the final string representation
    return stream.str();
}


// --------------------------------------------------------------------------------------------------------
// insert()
//  pre-condition: The hashed key must be a positive integer or within the table size.
//  post-condition: Inserts an element with data and key into the hash table.
//  parameters: data - The data to be inserted, key - The key associated with the data.
// --------------------------------------------------------------------------------------------------------

template <class T>
void HashTable<T>::insert(const T data, const int key) {
    if (size == 0) { // Check if the hash table is empty
        return; //If yes, tops the function 
    }

    int s = hash_func(key); //Calculate the hash index (slot) for the given key
    Elem *insertElem = new Elem();
    insertElem->node = Element<T>(data, key); //Create a new Element object with the given data and key

    //If the slot is empty, insert the new element as the first element in the slot
    if (table[s] == NULL) {
        table[s] = insertElem;
    }
    //If the slot is not empty, insert the new element at the beginning of the linked list 
    else {
        // Connect the new element's 'next' pointer to the current first element in the slot
        insertElem->next = table[s];
        // Update the 'prev' pointer of the current first element to point to the new element
        table[s]->prev = insertElem;
        // Update the table's slot to point to the new element, making it the new first element
        table[s] = insertElem;
    }

    return; //Exit the function after insertion
}




// --------------------------------------------------------------------------------------------------------
// remove()
//  pre-condition: The hashed key must be a positive integer or within the table size adn the element must be in the table.
//  post-condition: Removes an element with the given key from the hash table.
//  parameters: key - The key associated with the data.
// --------------------------------------------------------------------------------------------------------

template<class T>
void HashTable<T>:: remove(int key){
    if (size == 0) { // Check if the hash table is empty
        return; //If yes, stops the function (nothing to remove)
    }

    int s = hash_func(key); //Calculate the hash index (slot) for the given key
    //Check if the slot at index s is empty (no element with this key)
    if (table[s] == NULL) {
        return; //Nothing to remove
    }

    //Initialize a pointer to traverse the linked list at the slot s
    Elem *iter;
    iter = table[s];

    //Search for the element with the specified key within the linked list
    while(iter && iter->node.get_key() != key) {
        iter = iter->next; // If the element that iter points to is not the given key, move on to the next element 
    }

    // If 'iter' is NULL, indicate the element with the specified key was not found
    if (iter == NULL) {
        return;
    }

    //Adjust the pointers to remove the element that iter is currently pointing to from the linked list
    if (iter->prev != NULL) {
        iter->prev->next = iter->next;
    } else {
        table[s] = iter->next;
    }

    if (iter->next != NULL) {
        iter->next->prev = iter->prev;
    }

    delete iter; //deallocate memory for the removed element
}



// --------------------------------------------------------------------------------------------------------
// member()
//  pre-condition: The hashed key must be a positive integer or within the table size and the element must be in the table.
//  post-condition: Returns true if the element with the given key is in the hash table, false otherwise.
//  parameters: 
//  key - The key associated with the data
//  data - the data/element associated with the key
//  return type: bool
// --------------------------------------------------------------------------------------------------------

template <class T>
bool HashTable<T>:: member(const T data, const int key) const {
    if (size == 0) { // Check if the hash table is empty.
        return false; //If yes, return false
    }

    int s = hash_func(key); //Calculate the hash index (slot) for the given key
    if (table[s] == NULL) { //Check if the slot at the calculated index is empty (no elements)
        return false; //If yes, return false
    }
    
    //Initialize a pointer as the head of the linked list in slot s of the hash table
    Elem *iter;
    iter = table[s];

    //Traverse through the linked list at the slot s until a matching data and key is found
    while(iter && (iter->node.get_key() != key || iter->node.get_data() != data)) {
        iter = iter->next;
    }

    return !(iter == NULL); //Return true if a matching element was found in the hash table
}