//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// usecase.cpp
// This file contains the implementation of the usecase
// converting binary to hex value
//========================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "bst.h"
using namespace std;

//========================================================
// create_bst function
// pre-condition: a file of bin and hex values
// post-condition: a bst that for each node, key is 
// binary value and data is the corresponding hex value
// parameters: fname: name of the file
// return: a bst
//========================================================

template<class DataT, class KeyT>
BST<DataT, KeyT>* create_bst(string fname)
{
    ifstream inFile;
    inFile.open(fname); // open file to read info

    string hex, bin;
    BST<DataT, KeyT>* bst = new BST<DataT, KeyT>; // create bst

    while(!inFile.eof()) // while not end of the file
    {
        getline(inFile, hex, ','); // get hex
        getline(inFile, bin, '\n'); // get binary value
        
        if (hex == "") {
            continue;
        }

        bst->insert(hex, bin); // insert into bst

    }
    inFile.close(); // close file
    
    return bst;
}

//========================================================
// convert function
// pre-condition: a bst contaning node of bin and hex values
// post-condition: a string of hex value
// parameters: bst: a pointer to binary search tree;
// bin: a string of binary value
// return: a string of the corresponding hex value
//========================================================
template<class DataT, class KeyT>
string convert(BST<DataT, KeyT>* bst, string bin)
{   
    stringstream res;
    int mod = bin.length() % 4; // check if length is multiple of 4
    
    if (mod != 0) {
        for (int i=0; i < (4-mod); i++) {
            // add 0's to make the binary value length multiple of 4
            bin = "0" + bin; 
        }
    }

    for (int i=0; i < bin.length(); i=i+4) {
        // get group of 4 bits and convert to hex value
        res << bst->get(bin.substr(i, 4)); 
    }

    return res.str();
}