//========================================================
// Linh Mai, Bao Luu, Jeremiah Shelton
// CS271, Fall 2023
// minqueue.cpp
// This file contains the implementation of the MinQueue class
// specified in minqueue.h.
//========================================================

//Header files and standard namespace
#include <limits>
#include "minqueue.h"
#include <iomanip>
#include <sstream>
using namespace std;

//IMPLEMENTATION OF PRIVATE METHODS

//=================================================
// PARENT
// returns the index of a child element's parent element
// PARAMETERS:
// i: the index of the current child element
// RETURN VALUE:
// i/2: the index of the parent element
//Pre-condition: i should be a valid non-negative integer representing the index of the current child element 
//Post-condition: If the input i is valid, calculate and return the index of the parent element 
//=================================================
template <typename T>
int MinQueue<T>::PARENT(int i) {
    if(i<0){ //checking if the index is out of range
        cout << "Error: Array index out of range" << endl;
    }
    else {
        if (i % 2 == 1) {
            return i/2;
        }
        else {
            return i/2 - 1;
        }
    }
}

//=================================================
// LEFT
// returns the index of a child element on the left of the given parent element
// PARAMETERS:
// i: the index of the current parent element 
// RETURN VALUE:
// 2*i: the index of the left child element
//Pre-condition: The function expects an integer i as a parameter, representing the index of a parent element in a min heap array.
//Post-condition: returns an integer value equal to 2*i + 1, which represents the index of the left child element of the given parent element. If the input index i is less than 0, it prints an error message indicating that the array index is out of range.
//=================================================

template <typename T>
int MinQueue<T>::LEFT(int i) {
    if(i < 0){ //checking if the index is out of range
        cout << "Error: Array index out of range" << endl;
    }
    else{
        return 2*i+1; //if index is valid, return the left child element
    }
}

//=================================================
// RIGHT
// returns the index of a child element on the right of the given parent element
// PARAMETERS:
// i: the index of the current parent element
// RETURN VALUE:
// 2*i + 1: the index of the right child element
//Pre-condition:  it takes a positive integer i as a parameter, which represents the index of a parent element in an array-like structure
//Post-condition:  returns an integer, specifically 2*i + 2, which represents the index of the right child element of the given parent element. If the input index i is negative, it outputs an error message to indicate that the array index is out of range.
//=================================================
template <typename T>
int MinQueue<T>::RIGHT(int i) {
    if(i < 0){ //check if the index is out of range
        cout << "Error: array index out of range" << endl;
    } 
    else{
        return 2*i+2; // if index is valid, return the right child element
    }
}

//=================================================
// SWAP
// performs swap operation based on elements' indexes
// PARAMETERS:
// index1: index of the first element in the min-heap array
// index2: index of the second element in the min-heap array
// RETURN VALUE:
// none
//Pre-condition: The function is called with valid indices index1 and index2 within the bounds of the min-heap array.
//Post-condition: After the function is executed, the elements at index1 and index2 in the min-heap array have been swapped, effectively changing their positions
//=================================================
template <typename T>
void MinQueue<T>::SWAP(int index1, int index2) {
    T temp = *(HeapArray+index1); // declaring the temp variable that holds the value of index1's element position
    *(HeapArray+index1) = *(HeapArray+index2); // assigning the value of index2's element to index1 position 
    *(HeapArray+index2) = temp; // assigning the value of index1's element to index2 position
}

//IMPLEMENTATION OF PUBLIC METHODS

//=================================================
// DEFAULT CONSTRUCTOR
// initializes an empty heap array as soon as the class is called
// PARAMETERS: none
// RETURN VALUE:
// none
//=================================================
template <typename T>
MinQueue<T>::MinQueue(void) {
    HeapArray = new T [DEFAULT_LIST_CAPACITY]; //initializes the HeapArray to be an empty array of default capacity of 10
    array_size = DEFAULT_LIST_CAPACITY; // setting the default array size
    heap_size = 0; // setting the default heap size to 0 as the heap does not have any elements
}

//=================================================
// COPY CONSTRUCTOR
// creates a min priority queue (min-heap) of the n elements in array A
// PARAMETERS:
// A: the given array that needs to be copied 
// n: the number of elements in array A
// RETURN VALUE:
// none
//=================================================

template <typename T>
MinQueue<T>::MinQueue(T* A, int n) {
    // setting the heap size and array size to be the given array's size
    heap_size = n; 
    array_size = n;

    HeapArray = new T[n]; // initializing HeapArray to be an empty array of size n

    for (int i = 0; i < n; i++) {
        *(HeapArray+i) = A[i]; // copies each element of A to HeapArray in the exact same order/index position
    }

    build_heap(); //produces a min-heap array from the newly copied array
}

//=================================================
// DESTRUCTOR
// deletes the current HeapArray's array value as the program finishes
// PARAMETERS: none
// RETURN VALUE:
// none
//=================================================

template <typename T>
MinQueue<T>::~MinQueue(void) {
    delete [] HeapArray; // delete the HeapArray's array value 
}

//=================================================
// INSERT
// insert an element x into the priority queue
// PARAMETERS:
// x: the new element to be inserted into the priority queue
// RETURN VALUE:
// none
//Pre-condition: The function is called with a value x that needs to be inserted into the priority queue.
//Post-condition: the value x is inserted into the priority queue, and the priority queue maintains its  
//min-heap property. The heap size and array size may be updated to accommodate the new element, and the 
//decrease_key method is called to ensure that the min-heap properties are maintained.
//=================================================
template <typename T>
void MinQueue<T>::insert(T x) {
    if (heap_size == array_size) { //if the array's capacity is full, increase the array size 
        int longer;
        if (array_size != 0) {
            longer = array_size *2; //if current length != 0, double it
        } else {
            longer = array_size + 1;  //if current length == 0, increment
        }
        T* NewArray = new T[longer]; //create new array
        for (int i; i < array_size; i++) {
            *(NewArray + i) = *(HeapArray + i); //copy old array to new array element by element
        }
        delete [] HeapArray; //deallocate old array
        HeapArray = NewArray; // set the heap array to the newly created array
        array_size = longer; // update the sizing
    }

    int i = heap_size;         
    *(HeapArray + heap_size) = x;    //put x into end of heap array
    heap_size++;               //increase heap_size

    while (i > 0)
    {
        int parent = PARENT(i);  //variable representing index of parent node

        //if new element violates heap property, swap it with its parent, 
        //until heapArr[i] > heapArr[parent], x is in correct position
        if (HeapArray[i] < HeapArray[parent])  
        {
            SWAP(i, parent);
            i = parent;
        }
        else
            break;
    }

}

//=================================================
// MIN
// returns the smallest value in the queue
// PARAMETERS: none
// RETURN VALUE:
// *(HeapArray+0): the smallest value in the queue, which is at the root 
//Pre-condition: MinQueue object contains at least one element.
//Post-condition: returns the minimum element from the MinQueue represented by the HeapArray
//=================================================

template <typename T>
T MinQueue<T>::min() const {
    if (heap_size > 0) {
        return *(HeapArray+0);// return root of queue
    } else {
        return 0;
    }
}

//=================================================
// EXTRACT_MIN
// removes and returns the smallest value in the queue
// PARAMETERS: none
// RETURN VALUE:
// none
//Pre-condition: the min heap should not be empty
//Post-condition: remove and return the smallest value in the min-heap
//=================================================

template <typename T>
T MinQueue<T>::extract_min(void) {
    if (heap_size <= 0) { // check if heap is empty
        return 0; // If the heap is empty, return a default value
    }
    T min = (*this).min(); // Store the current minimum element    
    *(HeapArray+0) = *(HeapArray+(heap_size-1));// Replace the root (minimum element) with the last element in the heap
    heap_size --; //Reduce the heap size by 1
    min_heapify(0); //restore the heap property
    return min;
}

//=================================================
// DECREASE_KEY
// decrease the value at index i to the new value k
// PARAMETERS:
// i: the index of the element we need to assign new value to 
// k: the new value of the element at index i
// RETURN VALUE:
// none
//Pre-condition:  the MinQueue object is properly initialized, and the elements in the min-heap satisfy the min-heap property, and the value k should be less than or equal to the current value at index i
//Post-condition: the value at index i in the min-heap has been updated to k, and the min-heap property is restored for the entire heap, ensuring that the element at index i is in its correct position
//=================================================

template <typename T>
void MinQueue<T>::decrease_key(int i, T k) {
    // Check if the new value k is greater than the current value at index i
    if (i < 0 || i >= heap_size || *(HeapArray + i) <= k) {
        return; // No need to decrease the key; exit the function
    }
    *(HeapArray+i) = k; // Update the value at index i with the new value k

    // Maintain the min-heap property by repeatedly swapping elements
    // with their parent if the current element is smaller than its parent
    while (i>0) {
        int parent = PARENT(i);

        if (*(HeapArray + i) < *(HeapArray + parent)) {
            SWAP(i, parent);
            i = parent;
        }
        else {
            break;
        }
    }
}

//=================================================
// min_heapify
// maintains the heap property
// PARAMETERS:
// i: the index of the element that the min-heapify process starts and floats down from
// RETURN VALUE:
// none
//Pre-condition: The function assumes that the elements in the HeapArray form a valid min-heap with the exception of the element at index i.
//Post-condition: the element at index i will be correctly placed within the min-heap so that the min-heap property is maintained for the entire heap
//=================================================

template <typename T>
void MinQueue<T>::min_heapify(int i) {

    if (i < 0 || i > heap_size - 1) { // handling invalid index
        return; 
    }
    //retrieving the value of the left and right childs of the current element at index i
    int left = LEFT(i);
    int right = RIGHT(i);

    int smallest; //variable that stores the index of the smallest array obtained throughout each time min_heapify is called

    //cout << "comparing item " << *(HeapArray+left) << " at index " << left << " with item " << *(HeapArray+i) << " at index " << i << endl;
    // check if the left child element is smaller than the parent, assign its index to smallest
    if (left < heap_size && *(HeapArray+left) < *(HeapArray+i)) { 
        smallest = left;
    } 
    //if not, i is still the current smallest element 
    else {
        smallest = i;
    }
    //cout << "comparing item " << *(HeapArray+right) << " at index " << right << " with item " << *(HeapArray+smallest) << " at index " << smallest << endl;
    //check if the right child element is smaller than the parent, assign its index to smallest
    if (right < heap_size && *(HeapArray+right) < *(HeapArray+smallest)) {
        smallest = right;
    }
    //after the 2 comparisons, check if the smalllest element is still the parent element or any of the 2 children
    if (smallest != i) {
        //if the smallest element is not in the parent index, swap the parent element's index with the smallest element's index
        SWAP(smallest, i);
        min_heapify(smallest);
    }
}

//=================================================
// build_heap
// produce a min-heap from potentially unordered values in the member array
// PARAMETERS: none
// RETURN VALUE:
// none
//Pre-condition:  The MinQueue object should have a valid array_size and HeapArray containing potentially unordered values. The array_size should accurately reflect the size of the array
//Post-condition: the MinQueue object will have a valid min-heap structure, and the heap_size will be set equal to array_size. The min-heap property will be satisfied for all elements in the HeapArray.
//=================================================
template <typename T>
void MinQueue<T>::build_heap() {
    if (array_size == 0) { //calling build_heap on an empty heap does nothing
        return;
    }
    heap_size = array_size; //set the heap size to be equal to the member array

    for (int i = array_size/2 - 1; i >= 0; i--) { //start from the middle element of the array to the top. After each iteration, i is decremented
        min_heapify(i); //run min-heapify for each parent node to satisfy the min-heap property for each subtree being considered during each iteration
    }
}


//=================================================
// sort
// sort the min-heap member array in ascending order
// PARAMETERS:
// A: the array that needs to be sorted
// RETURN VALUE:
// none
// Pre-condition: The MinQueue object should be properly initialized and contain elements for sorting
// Post-condition: the MinQueue is sorted in ascending order, and the sorted elements are copied back into the array A, effectively sorting the input array A.
//=================================================
template <typename T>
void MinQueue<T>::sort(T *A) {
    // Copy the elements from array A into the MinQueue's HeapArray
    for (int i = 0; i < heap_size; i++) {
        *(HeapArray+i) = *(A+i);
    }
    build_heap(); // Build a min-heap from the elements in the HeapArray

     // Store the original heap size and extract elements (sorted in ascending order)
    int old_heap_size = heap_size;
    for (int i = 0; i < old_heap_size; i++) {
        // Extract the minimum element from the min-heap
        T item = extract_min();
        // Store the extracted minimum element back into array A
        *(A+i) = item;
    }
}

//=================================================
// TO_STRING
// convert arrays to string
// PARAMETERS: none
// RETURN VALUE:
// stream.str(): a string with the elements in your priority separated by a single space in the order in which they appear in the member array
//=================================================
template <typename T>
string MinQueue<T>::to_string(void) {
    stringstream stream; //stringstream to store queue in
    for (int i = 0; i < heap_size; i++) {
        stream << *(HeapArray+i); // add queue elements
        if (i != (heap_size - 1)) {
            stream << " "; // add space if not final member
        }
    }
    return stream.str();
}

//=================================================
// SET
// set index to a new value
// PARAMETERS:
// i: index of the element that needs replacement
// val: value of the new element
// RETURN VALUE:
// none
// Pre-condition: i parameter is a valid index within the bounds of the array
// Post-condition:  the value at the specified index i in the HeapArray is set to the new value val. If the index is out of range, an error message is printed, but the array remains unchanged
//=================================================

template <typename T>
void MinQueue<T>::set(int i, T val) {
    if ( i >= heap_size) { //check if index is out of range
        return;
    } else {
        *(HeapArray + i) = val; //if index is valid, then assign the value at index i to val
    }
}

//=================================================
// ALLOCATE
// ensure member array's capacity
// PARAMETERS:
// n: the given number of elements that the array's size will be compared to
// RETURN VALUE:
// none
// Pre-condition: The MinQueue object should be properly initialized, and n should be a non-negative integer representing the desired number of elements.
// Post-condition:  the MinQueue object ensures that its internal array has a capacity equal to or greater than n, and it may reallocate memory if necessary to achieve this capacity.
//=================================================

template <typename T> 
void MinQueue<T>::allocate(int n) {

    heap_size = n;
    array_size = n;
    HeapArray = new T[n];
}