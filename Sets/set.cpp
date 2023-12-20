//========================================================
// Linh Mai, Bao Luu, Jeremiah Shelton
// CS271, Fall 2023
// set.cpp
// This file contains the implementation of the Set class
// specified in set.h.
//========================================================

// Header files and standard namespace
#include "set.h"
#include <iomanip>
#include <sstream>
using namespace std;

//=================================================
// Default constructor
// Creates an empty Set
// PARAMETERS:
// none
// RETURN VALUE:
// none, an empty Set is created
//=================================================
template <typename T>
Set<T>::Set (void) {
    head = NULL;
}

//=================================================
// Copy constructor
// Creates a Set object identical to the parameter
// of type Set
// PARAMETERS:
// otherSet: the Set object to copy from
// RETURN VALUE:
// creates a Set object with the same elements in
// each node
//=================================================
template <typename T>
Set<T>::Set (const Set<T> &otherSet) {
    if (otherSet.head == NULL) { // creates an empty list if the other list is empty
        head = NULL;
    }
    else {
        head = new Node;
        Node* temp = head; // pointer that iterates through called Set
        Node* otherTemp = otherSet.head; // pointer that iterates through parameter Set
        while (otherTemp->next != NULL) {
            temp->item = otherTemp->item; // copies item
            temp->next = new Node;
            temp = temp->next; // goes to next node
            otherTemp = otherTemp->next; // goes to next node
        }
        temp->item = otherTemp->item; // copies last item
        temp->next = NULL; // make last pointer point to NULL
        temp = NULL;
        otherTemp = NULL;
    }
}

//=================================================
// Destructor
// Destructs the called Set object
// PARAMETERS:
// none
// RETURN VALUE:
// none, called Set object is deallocated
//=================================================
template <typename T>
Set<T>::~Set (void) {
    if (not empty()) { // if empty, nothing needs to be done
        Node* temp = head; //pointer 1
        Node* temp2 = temp->next; // pointer 2 that is after pointer 1
        while (temp2 != NULL) {
            delete temp; // deletes item at pointer 1
            temp = temp2; // iterates pointer 1
            temp2 = temp->next; // iterates pointer 2
        }
        delete temp; // deletes last item
        temp = NULL;
    }
}

//=================================================
// insert
// Inserts an item to the head of the Set object
// PARAMETERS:
// x: element to be inserted
// RETURN VALUE:
// none, the Set object has the new element at its
// head
// Pre-condition: x must be of type T and is not
// in the Set yet
//=================================================
template <typename T>
void Set<T>::insert(T x) {
    if (not contains(x)) { // only runs if x is not already in the list
    Node* temp = new Node; // new node to store x
    temp->item = x;
    temp->next = head;
    head = temp; // assigns head to point to new node
    }
}

//=================================================
// remove
// Removes the specified item from the Set object
// PARAMETERS:
// x: element to remove
// RETURN VALUE:
// none, the Set object has the specified item removed
// Pre-condition: x must be already inside the Set
//=================================================
template <typename T>
void Set<T>::remove(T x) {
    if (not contains(x)) { // returns if x is not in the set
        return;
    }
    Node* temp = head; // pointer 1
    Node* nextItem = temp->next; // pointer 2
    if (temp->item == x) { // if the item to delete is at head
        head = nextItem;
        delete temp;
        return;
    }
    while (nextItem->item != x) { // while x is not found
        nextItem = nextItem->next; // iterates pointer 2
        temp = temp->next; // iterates pointer 1
    }
    nextItem = nextItem->next; // makes pointer 2 point to the item next to the item to delete
    delete temp->next;
    temp->next = nextItem; // makes next of pointer 1 point to pointer 2, reconnecting the list
}

//=================================================
// cardinality
// Returns the cardinality of the Set object
// PARAMETERS:
// none
// RETURN VALUE:
// The number of elements currently in the object
//=================================================
template <typename T>
int Set<T>::cardinality(void) const {
    Node* temp = head; // pointer that iterates through the set
    int cardinality = 0; // variable that counts cardinality
    while (temp != NULL) {
        cardinality++; // increments cardinality by 1 for each iteration of the loop
        temp = temp->next; // iterate pointer
    }
    return cardinality;
}

//=================================================
// empty
// Checks whether the Set object is empty or not
// PARAMETERS:
// none
// RETURN VALUE:
// A boolean value indicating whether the Set object
// is empty
//=================================================
template <typename T>
bool Set<T>::empty(void) const {
    return (head == NULL);
}

//=================================================
// contains
// Checks whether the Set object contains an item
// PARAMETERS:
// x: the item to check
// RETURN VALUE:
// A boolean value indicating whether the Set object
// contains the specified item
//=================================================
template <typename T>
bool Set<T>::contains(T x) const {
    Node* temp = head; // pointer that iterates through the list
    while ((temp != NULL) && (temp->item != x)) { // loop that runs until either pointer iterates through the entire set or x is found
        temp = temp->next;
    }
    if (temp == NULL) { // set has been fully iterated, meaning x is not found
        return false;
    }
    return true;
}

//=================================================
// to_string
// Converts the Set object into a string
// PARAMETERS:
// none
// RETURN VALUE:
// a string representing the Set object, with elements
// separated by a space
//=================================================
template <typename T>
string Set<T>::to_string(void) const {
    Node* temp = head; // pointer to iterate through set
    stringstream stream; // stringstream to store set in string form
    while (temp != NULL) {
        stream << temp->item; // add item to stringstream
        temp = temp->next; // iterates pointer
        if (temp != NULL) {
            stream << " "; // add a space if item is not the last item in the list
        }
    }
    temp = NULL;
    return stream.str();
}

//=================================================
// Operator "==" (equal) overload
// Overload the "==" operator to allow 2 Set objects
// to be compared for equality
// PARAMETERS:
// t: the other Set object that will be checked against
// the called Set object
// RETURN VALUE:
// a boolean value indicating whether these 2 Set
// objects are equal
//=================================================
template <typename T>
bool Set<T>::operator==(const Set<T> &t) const {
    if (empty()) { 
        if (t.empty()) { // checks if both sets are empty
            return true; 
        }
        return false;
    }
    if (cardinality() != t.cardinality()) { // returns false if they aren't the same size
        return false;
    }
    Node* temp = head; // pointer to iterate through the set
    T item; // variable that stores item to be checked
    while (temp != NULL) {
        item = temp->item;
        if (not t.contains(item)) { // check if an item in called set is also in t
            return false;
        }
        temp = temp->next; // iterates pointer
    }
    return true;
}

//=================================================
// Operator "<=" (subset) overload
// Overload the "<=" operator which can be used to
// check if a Set object is the subset of another
// Set object
// PARAMETERS:
// t: the other Set object that will be checked against
// the called Set object
// RETURN VALUE:
// a boolean value indicating whether the called Set
// object is a subset of the t Set object
//=================================================

template <typename T>
bool Set<T>::operator<=(const Set<T> &t) const
{
    //Pre-condition: 'head' is a pointer to the beginning of the current set (let's say set 's').
    //'t.head' is a pointer to the beginning of the set 't'.

    Node *temp = head; //head pointer of the set s
    Node *tPtr = t.head; //head pointer of the set t

    // check if the two sets are both empty, then they are each other's subset (true)
    if (temp == NULL && tPtr == NULL) {
        return true;
    }
    
    while (temp != NULL && tPtr != NULL)
    {
        //the loop starts by checking if the current two elements of two 
        if (temp->item == tPtr->item)
        {
            temp = temp->next;
            tPtr = t.head;
            continue;
        }
        // If the current elements do not match, move to the next element in set 't' and continue to compare it with the current element of set s.
        tPtr = tPtr->next;

        // If we reach the end of set 't' without finding a match in set 's', 's' is not a subset of 't'
        if (tPtr == NULL)
        {
            return false;
        }
        // If the temp pointer reach the end of set 's', it means all of its elements are present in set 't', then the set 's' is a subset of set 't'
        if (temp == NULL) {
            return true;
        }
    }

    return true;
    // Post-condition: The method returns 'true' if set 's' is a subset of set 't'.
}

//=================================================
// Operator "+" (union) overload
// Overload the "+" operator that creates an union
// of 2 Set objects
// PARAMETERS:
// t: the other Set object that will be used along with
// the called Set object to create an union
// RETURN VALUE:
// a new Set object that is the union of the 2 Set
// objects
//=================================================
template <typename T>
 Set<T> Set<T>::operator+(const Set<T> &t) const {
    Set<T> newSet; //new set to be returned
    Node* temp = t.head; // pointer that iterates through set t
    T item;
    if (not t.empty()) { // insert items in t only if t is not empty
        while (temp != NULL) {
            item = temp->item;
            newSet.insert(item); // insert item
            temp = temp->next; // iterates pointer
        }
    }
    temp = head; // move on to inserting item in called set
    if (not empty()) { // code only run if called set is not empty
        while (temp != NULL) {
            item = temp->item;
            if (not newSet.contains(item)) { // check if item is already in new set
                newSet.insert(item);
            }
            temp = temp->next; // iterates pointer
        }
    }
    return newSet;
}

//=================================================
// Operator "&" (intersection) overload
// Overload the "&" operator to create an intersection
// of 2 Set objects
// PARAMETERS:
// t: the other Set object that will be used along with
// the called Set object to create an intersection
// RETURN VALUE:
// a new Set object that is the intersectionof the
// 2 Set objects
//=================================================
template <typename T>
Set<T> Set<T>::operator&(const Set<T> &t) const {
    Set<T> newSet; //new set to be returned
    if ((not empty()) && (not t.empty())) { // code only needs to run if both sets aren't empty. if either of them is, empty set is returned
        Node* temp = head; // pointer that iterates through list
        T item; // variable that stores item
        while (temp != NULL) {
            item = temp->item;
            if (t.contains(item)) { // checks if item is also in set t
                newSet.insert(item); // insert item into new set
            }
            temp = temp->next; // iterates pointer
        }
    }
    return newSet;
}

//=================================================
// Operator "-" (difference) overload
// Overload the "-" operator that creates a Set object
// that is the difference of 2 Set objects
// PARAMETERS:
// t: the other Set object that will be used along with
// the called Set object to create a difference
// RETURN VALUE:
// a new Set object that is the difference of the
// called Set object to the parameter Set object
//=================================================
template <typename T>
Set<T> Set<T>::operator-(const Set<T> &t) const {
    Set<T> newSet; //new set to be returned
    if (not empty()) { // check if called set is empty, returns empty set if true
        Node* temp = head; // pointer to iterate through set
        T item; // variable to store item
        while (temp != NULL) {
            item = temp->item;
            if (not t.contains(item)) { // if item in called set is not in set t
                newSet.insert(item); // insert item
            }
            temp = temp->next; //iterates pointer
        }
    }
    return newSet;
}