#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../header/usecase.h"

using namespace std;

// --------------------------------------------------------------------------------------------------------
// create_table()
//  pre-condition: The file must be in the correct format.
//  post-condition: Creates a hash table from the given file.
//  parameters: fname - The name of the file to be read, m - The size of the hash table.
//  return type: HashTable<T>*
// --------------------------------------------------------------------------------------------------------

template <class T>
HashTable<T>* create_table (string fname, int m) {
    //Create a new hash table of size m
    HashTable<T>* ht = new HashTable<T> (m);

    //Open the input file for reading
    std::ifstream inputFile("./data/" + fname);

    //Check if the file was successfully opened
    if (!inputFile.is_open()) {
        // Print an error message to the standard error stream if file cannot be opened
        std::cerr << "Error: Unable to open the file." << std::endl;
        return ht; //return the initialized hash table due to the error
    }

    //Read the file line by line
    string line;
    while (getline(inputFile, line)) {
        //Create a stringstream to parse the line into tokens
        istringstream tokenStream(line);

        //Extract the username from the line 
        string username;
        getline(tokenStream, username, ',');
        
        //Extract the password from the line
        string password;
        getline(tokenStream, password, ',');

        //Calculate the hash key based on the password and insert it into the hash table
        int key = ht->hash_func(stoll(password) % m);
        ht->insert(username, key);
    }

    inputFile.close(); //close the input file
    return ht; //return the populated hash table
}

// --------------------------------------------------------------------------------------------------------
// login()
//  pre-condition: The hashed key must be a positive integer or within the table size and element (username and password) should be in the table.
//  post-condition: Returns true if the username and password match an element in the hash table.
//  parameters: ht - The hash table to be searched, username - The username to be searched for, password - The password to be searched for.
//  return type: bool
// --------------------------------------------------------------------------------------------------------

template <class T>
bool login (HashTable<T>* ht, T username, string password) {
    //Calculate the key by taking the remainder of the hashed password with the table size
    int key = ht->hash_func(stoll(password) % ht->size);

    //Call the member function of the hash table to check if the username exists at the calculated key
    return ht->member(username, key);
}

