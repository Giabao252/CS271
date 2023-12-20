//
//  test_bst_example.cpp
//  CS 271 BST Project: Example Test File
//
//  Created by Dr. Stacey Truex
//
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <typeinfo>
#include "usecase.cpp"
#include "bst.cpp"

using namespace std;

int int_data[10] = {1, 17, 42, 56, 73, 29, 88, 11, 64, 95};
char char_data[10] = {'B', 'H', 'E', 'L', 'D', 'J', 'K', 'A', 'Z','X'};
string string_data[10] = {"Lion", "Elephant", "Giraffe", "Tiger", "Penguin", "Zebra", "Kangaroo", "Monkey", "Crocodile", "Flamingo"};
bool bool_data[2] = {true, false};
float float_data[10] = {23.45, 57.89, 4.12, 36.78, 92.34, 11.67, 68.90, 30.56, 84.21, 2.34};

int int_key[10] = {42, 17, 73, 9, 56, 31, 88, 24, 65, 3};
char char_key[10] = {'Z', 'Q', 'W', 'B', 'M', 'K', 'D', 'R', 'X', 'C'};
string string_key[10] = {"Apple", "Microsoft", "Google", "Amazon", "Samsung", "IBM", "Intel", "Dell", "HP", "Sony"};
bool bool_key[2] = {true, false};
float float_key[10] = {12.34, 45.67, 89.01, 23.45, 67.89, 10.20, 54.32, 98.76, 21.43, 65.87};

int int_left_skewed[10] = {10,9,8,7,6,5,4,3,2,1};
int int_right_skewed[10] = {1,2,3,4,5,6,7,8,9,10};

template<class DataT, class KeyT>
void test_empty(DataT data, KeyT key) { //data and key are values to be inserted/var types of BST
    try
    {
        BST<DataT, KeyT> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(data,key);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.remove(key);
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl; //testing empty after insert
        }
        bst.insert(data,key);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}
void EmptyTests(){
    test_empty<int,int>(1,1);
    test_empty<char,char>('a','a');
    test_empty<string,string>("hello","hello");
    test_empty<float,float>(4.20,4.20);
    test_empty<bool,bool>(true,true);
    cout << "Test Empty Done" << endl;
    return;
}

template<class DataT, class KeyT>
void test_insert(DataT data[],KeyT key[],string expectedString,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        string bst_str;
        bst_str = bst.to_string();
        if(bst_str != expectedString) {
            cout << "Incorrect result of inserting keys in order. Expected " << expectedString << " but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}
void test_insert_null() {
    try {
        BST<int, int> bst_int;
        bst_int.insert(NULL,NULL); //inserting NULL
        string bst_str;
        bst_str = bst_int.to_string();
        if(bst_str != "0") {
            cout << "Incorrect result of inserting keys in order. Expected 0 but got : " << bst_str << endl;
        }

        bst_int.insert(13,12); //inserting after inserting NULL
        bst_str = bst_int.to_string();
        if(bst_str !=  "0 12") {
            cout << "Incorrect result of inserting keys after inserting NULL. Expected 0 12 but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}
void InsertTests(){
    
    //INSERT TESTS
    //1. Different Data Types
    test_insert <int,char> (int_data,char_key,"Z Q B W M R X K D C",false);
    test_insert <int,int> (int_data,int_key,"42 17 73 9 31 56 88 3 24 65",false);
    test_insert <int,float> (int_data,float_key,"12.34 10.2 45.67 23.45 89.01 21.43 67.89 98.76 54.32 65.87",false);
    test_insert <int,string> (int_data,string_data,"Lion Elephant Tiger Crocodile Giraffe Penguin Zebra Flamingo Kangaroo Monkey",false);
    test_insert <int,bool> (int_data,bool_data,"1 0",true);

    //2. Edge Cases
    test_insert <int,int> (int_data,int_data,"1 17 11 42 29 56 73 64 88 95",false); //inserting integer pairs where key=data
    test_insert <string,string> (string_data,string_data,"Lion Elephant Tiger Crocodile Giraffe Penguin Zebra Flamingo Kangaroo Monkey",false); //inserting string pairs where key=data
    test_insert <char,char> (char_data,char_data,"B A H E L D J Z K X",false); //inserting char pairs where key=data
    test_insert <bool,bool> (bool_data,bool_data,"1 0",true); //inserting boolean pairs where key=data
    test_insert <float,float> (float_data,float_data,"23.45 4.12 57.89 2.34 11.67 36.78 92.34 30.56 68.9 84.21",false); //inserting float pairs where key=data
    test_insert <float,int> (float_data,int_left_skewed,"10 9 8 7 6 5 4 3 2 1",false); //insert only on one side of the tree
    test_insert <float,int> (float_data,int_right_skewed,"1 2 3 4 5 6 7 8 9 10",false); //insert only on the other side of the tree
    test_insert_null();
    

    cout << "Test Insert Done" << endl;
    return;
}

template<class DataT, class KeyT>
void test_get(DataT data[],KeyT key[]) {
    try {
        BST<DataT, KeyT> bst;
         for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]);
        }
        DataT val;
         for(int i = 0; i < 10; i++) { //get from top to bottom of tree
            val = bst.get(key[i]);
            if (val != data[i]){
            cout << "Incorrect get result. Expected " << data[i] << " but got : " << val << endl;
            }
        }
        
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}
void test_get_bool(int data[]) {
    try {
        BST<int, bool> bst;
        int val = bst.get(NULL); //get from empty BST
        if(val!=NULL) {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert(data[0], false);
        val = bst.get(false);
        if (val != data[0]){
            cout << "Incorrect get result. Expected " << data[0] << " but got : " << val << endl;
        }
        bst.insert(data[1], true);
        val = bst.get(true);
        if (val != data[1]){
            cout << "Incorrect get result. Expected " << data[1] << " but got : " << val << endl;
        }
        
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}
void GetTests(){
    test_get<int,int>(int_data,int_key);
    test_get<char,char>(char_data,char_key);
    test_get<float,float>(float_data,float_key);
    test_get<string,string>(string_data,string_key);

    test_get<int,int>(int_data,int_data);
    test_get<char,char>(char_data,char_data);
    test_get<float,float>(float_data,float_data);
    test_get<string,string>(string_data,string_data);\

    test_get<int,char>(int_data,char_key);
    test_get<float,char>(float_data,char_key);

    test_get<int,int>(int_right_skewed,int_right_skewed);
    test_get<int,int>(int_left_skewed,int_left_skewed);

    test_get_bool(int_data);
    cout << "Test Get Done" << endl;
    return;
}

template<class DataT, class KeyT>
void test_remove(DataT data[],KeyT key[],string expectedString,KeyT removedKey,bool keyBool) {
   try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        bst.remove(removedKey);
        string bst_str;
        bst_str = bst.to_string();
        if(bst_str != expectedString) {
            cout << "Incorrect result of removing keys. Expected " << expectedString << " but got : " << bst_str << endl;
        }
        

    } catch(exception& e) {
        cerr << "Error removing from bst : " << e.what() << endl;
    }
}

void RemoveTests(){
    //REMOVE TESTS
    //1. Different Data Types
    test_remove <int,char> (int_data,char_key,"Z R B W M X K D C",'Q',false);
    test_remove <int,int> (int_data,int_key,"42 17 73 3 31 56 88 24 65",9,false);
    test_remove <int,float> (int_data,float_key,"12.34 45.67 23.45 89.01 21.43 67.89 98.76 54.32 65.87",10.2,false);
    test_remove <int,string> (int_data,string_data,"Monkey Elephant Tiger Crocodile Giraffe Penguin Zebra Flamingo Kangaroo","Lion",false);
    test_remove <int,bool> (int_data,bool_data,"0","1",true);

    //2. Edge Cases
    test_remove <int,char> (int_data,char_key,"Z Q B W M R X K D C",'P',false); //removing element not in list
    test_remove <int,char> (int_data,char_key,"Q B W M R X K D C",'Z',false); //removing first element
    test_remove <int,char> (int_data,char_key,"Z Q B W M R X K D",'C',false); //removing last element
    test_remove <int,int> (int_data,int_left_skewed,"10 9 8 6 5 4 3 2 1",7,false); //removing from skewed tree
    test_remove <int,int> (int_data,int_right_skewed,"1 2 3 4 5 6 7 9 10",8,false); //removing from skewed tree
    cout << "Test Remove Done" << endl;
}

template<class DataT, class KeyT>
void test_max_data(DataT data[],KeyT key[],DataT expected,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        DataT temp = bst.max_data();
        if(temp != expected) {
            cout << "Incorrect result of retrieving max data. Expected " << expected << " but got : " << temp << endl;
        }

    } catch(exception& e) {
        cerr << "Error retrieving max data from bst : " << e.what() << endl;
    }
}

void test_max_data_misc() {
    try {
        BST<int,int> bst;
        int temp = bst.max_data();
        if(temp != NULL) {
            cout << "Incorrect result of inserting keys in order. Expected 0 but got : " << temp << endl;
        }
        bst.insert(1,2);
        temp = bst.max_data();
        if(temp != 1) {
            cout << "Incorrect result of retrieving max data after retrieving NULL. Expected 1 but got : " << temp << endl;
        }
    } catch(exception& e) {
        cerr << "Error finding max data into bst : " << e.what() << endl;
    }
}

void MaxDataTests(){
    //Data Types
    test_max_data <int,char> (int_data,char_key,1,false);
    test_max_data <int,int> (int_data,int_key,88,false);
    test_max_data <int,float> (int_data,float_key,11,false);
    test_max_data <int,string> (int_data,string_data,29,false);
    test_max_data <int,bool> (int_data,bool_data,1,true);

    test_max_data <char,int> (char_data,int_key,'K',false);
    test_max_data <float,int> (float_data,int_key,68.9,false);
    test_max_data <string,int> (string_data,int_data,"Flamingo",false);
    test_max_data <char,bool> (char_data,bool_data,'B',true);


    //Edge Cases
    test_max_data_misc();
    test_max_data <int,int> (int_data,int_left_skewed,1,false); //removing from skewed tree
    test_max_data <int,int> (int_data,int_right_skewed,95,false); //removing from skewed tree
    cout << "Test Max Data Done" << endl;
    return;
}


template<class DataT, class KeyT>
void test_max_key(DataT data[],KeyT key[],KeyT expected,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        KeyT temp = bst.max_key();
        if(temp != expected) {
            cout << "Incorrect result of retrieving max data. Expected " << expected << " but got : " << temp << endl;
        }

    } catch(exception& e) {
        cerr << "Error finding max key into bst : " << e.what() << endl;
    }
}
void test_max_key_misc() {
    try {
        BST<int,int> bst;
        int temp = bst.max_key();
        if(temp != NULL) {
            cout << "Incorrect result of inserting keys in order. Expected 0 but got : " << temp << endl;
        }
        bst.insert(1,2);
        temp = bst.max_key();
        if(temp != 2) {
            cout << "Incorrect result of retrieving max data after retrieving NULL. Expected 1 but got : " << temp << endl;
        }
    } catch(exception& e) {
        cerr << "Error finding max key into bst : " << e.what() << endl;
    }
}
void MaxKeyTests(){
    //Key Types
    test_max_key <int,char> (int_key,char_key,'Z',false);
    test_max_key <int,int> (int_key,int_key,88,false);
    test_max_key <int,float> (int_key,float_key,98.76,false);
    test_max_key <int,string> (int_key,string_data,"Zebra",false);
    test_max_key <int,bool> (int_key,bool_key,true,true);

    test_max_key <char,int> (char_key,int_key,88,false);
    test_max_key <float,int> (float_key,int_key,88,false);
    test_max_key <string,int> (string_data,int_key,88,false);
    test_max_key <char,bool> (char_key,bool_key,1,true);

    //Edge Cases
    test_max_key_misc();
    test_max_key <int,int> (int_left_skewed,int_data,95,false); //removing from skewed tree
    test_max_key <int,int> (int_right_skewed,int_data,95,false); //removing from skewed tree
    cout << "Test Max Key Done" << endl;
    return;
}


template<class DataT, class KeyT>
void test_min_data(DataT data[],KeyT key[],DataT expected,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        DataT temp = bst.min_data();
        if(temp != expected) {
            cout << "Incorrect result of retrieving min data. Expected " << expected << " but got : " << temp << endl;
        }

    } catch(exception& e) {
        cerr << "Error finding min data into bst : " << e.what() << endl;
    }
}
void test_min_data_misc() {
    try {
        BST<int,int> bst;
        int temp = bst.min_data();
        if(temp != NULL) {
            cout << "Incorrect result of inserting keys in order. Expected 0 but got : " << temp << endl;
        }
        bst.insert(1,2);
        temp = bst.min_data();
        if(temp != 1) {
            cout << "Incorrect result of retrieving min data after retrieving NULL. Expected 1 but got : " << temp << endl;
        }
    } catch(exception& e) {
        cerr << "Error finding min data into bst : " << e.what() << endl;
    }
}
void MinDataTests(){
    //Data Types
    test_min_data <int,char> (int_data,char_key,56,false);
    test_min_data <int,int> (int_data,int_key,95,false);
    test_min_data <int,float> (int_data,float_key,29,false);
    test_min_data <int,string> (int_data,string_data,64,false);
    test_min_data <int,bool> (int_data,bool_data,17,true);

    test_min_data <char,int> (char_data,int_key,'X',false);
    test_min_data <float,int> (float_data,int_key,2.34,false);
    test_min_data <string,int> (string_data,int_data,"Lion",false);
    test_min_data <char,bool> (char_data,bool_data,'H',true);

    //Edge Cases
    test_min_data_misc();
    test_min_data <int,int> (int_data,int_left_skewed,95,false); //removing from skewed tree
    test_min_data <int,int> (int_data,int_right_skewed,1,false); //removing from skewed tree
    cout << "Test Min Data Done" << endl;
    return;
}



template<class DataT, class KeyT>
void test_min_key(DataT data[],KeyT key[],KeyT expected,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        KeyT temp = bst.min_key();
        if(temp != expected) {
            cout << "Incorrect result of retrieving min data. Expected " << expected << " but got : " << temp << endl;
        }

    } catch(exception& e) {
        cerr << "Error finding min key in bst : " << e.what() << endl;
    }
}
void test_min_key_misc() {
    try {
        BST<int,int> bst;
        int temp = bst.min_key();
        if(temp != NULL) {
            cout << "Incorrect result of inserting keys in order. Expected 0 but got : " << temp << endl;
        }
        bst.insert(1,2);
        temp = bst.min_key();
        if(temp != 2) {
            cout << "Incorrect result of retrieving min data after retrieving NULL. Expected 1 but got : " << temp << endl;
        }
    } catch(exception& e) {
        cerr << "Error finding min key in bst : " << e.what() << endl;
    }
}
void MinKeyTests(){
    //Key Types
    test_min_key <int,char> (int_key,char_key,'B',false);
    test_min_key <int,int> (int_key,int_key,3,false);
    test_min_key <int,float> (int_key,float_key,10.2,false);
    test_min_key <int,string> (int_key,string_data,"Crocodile",false);
    test_min_key <int,bool> (int_key,bool_key,false,true);

    test_min_key <char,int> (char_key,int_key,3,false);
    test_min_key <float,int> (float_key,int_key,3,false);
    test_min_key <string,int> (string_data,int_key,3,false);
    test_min_key <char,bool> (char_key,bool_key,0,true);

    //Edge Cases
    test_min_key_misc();
    test_min_key <int,int> (int_left_skewed,int_data,1,false); //removing from skewed tree
    test_min_key <int,int> (int_right_skewed,int_data,1,false); //removing from skewed tree
    cout << "Test Min Key Done" << endl;
    return;
}

template<class DataT, class KeyT>
void test_successor(DataT data[],KeyT key[],KeyT inputIndex,KeyT expected,bool keyBool) {
    try {
        BST<DataT, KeyT> bst;
        if (keyBool == true){ //bool testing fix this!
            for(int i = 0; i < 2; i++) {
            bst.insert(data[i], key[i]) ;
            }
        }
        
        else{
        for(int i = 0; i < 10; i++) {
            bst.insert(data[i], key[i]) ;
        }
        }
        KeyT bst_successor = bst.successor(inputIndex);
        if(bst_successor != expected) {
            cout << "Incorrect result of finding successor key. Expected " << expected << " but got : " << bst_successor << endl;
        }

    } catch(exception& e) {
        cerr << "Error finding successor in bst : " << e.what() << endl;
    }
}

void SuccessorTests(){


    test_successor <int,char> (int_key,char_key,'C','D',false);
    test_successor <int,int> (int_key,int_key,17,24,false);
    test_successor <int,float> (int_key,float_key,54.32,65.87,false);
    test_successor <int,string> (int_key,string_key,"Google","HP",false);
    test_successor <int,bool> (int_key,bool_key,false,true,true);

    //Edge Cases
    //Finding successor of last value
    test_successor <int,char> (int_key,char_key,'Z',NULL,false);
    test_successor <int,int> (int_key,int_key,88,NULL,false);
    test_successor <int,float> (int_key,float_key,98.76,NULL,false);
    //test_successor <int,string> (int_key,string_data,"Zebra","Zebra",false);
    test_successor <int,bool> (int_key,bool_key,true,NULL,true);

    test_successor <int,char> (int_key,char_key,'P',NULL,false); //successor of node that is not in bst
    
    //Finding successor of first value
    test_successor <int,char> (int_key,char_key,'B','C',false);
    test_successor <int,int> (int_key,int_key,3,9,false);
    test_successor <int,float> (int_key,float_key,10.2,12.34,false);
    test_successor <int,string> (int_key,string_key,"Amazon","Apple",false);
    test_successor <int,bool> (int_key,bool_key,true,false,true);
    cout << "Test Successor Done" << endl;
    return;
}

void test_in_order() {
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }

    try {
        BST<string, int> bst;
        string bst_str = bst.in_order();
        if(bst_str != "") {
            cout << "Incorrect in_order result of empty tree. Expected but got : " << bst_str << endl;
        }
        int vals[12] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10, 3, 3};
        BST<string, int> bst2;
        for(int i = 0; i < 12; i++) {
            bst2.insert("some data", vals[i]);
        }
        bst_str = bst2.in_order();
        if(bst_str != "1 2 3 3 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10, 3, 3}. Expected 1 2 3 3 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }

    try {
        BST<string, string> bst;
        string bst_str = bst.in_order();
        if(bst_str != "") {
            cout << "Incorrect in_order result of empty tree. Expected but got : " << bst_str << endl;
        }
        string vals[7] = {"apple", "banana", "cherry", "apple", "date", "fig", "banana"};
        BST<string, string> bst2;
        for(int i = 0; i < 7; i++) {
            bst2.insert("some data", vals[i]);
        }
        bst_str = bst2.in_order();
        if(bst_str != "apple apple banana banana cherry date fig") {
            cout << "Incorrect in_order result after inserting keys {apple, banana, cherry, apple, date, fig, banana}. Expected apple apple banana banana cherry date fig but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim() {
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
               if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
    try {
        BST<string,int> bst;
        bst.trim(1,5);
        string bst_str = bst.to_string();
        if(bst_str != "") {
            cout << "Incorrect tree after trimming empty tree with low=1, high=5. Expected but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(100,101);
        bst_str = bst2.to_string();
        if(bst_str != "") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=100, high=101. Expected but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(-4,5);
        string bst_str = bst.to_string();
        if(bst_str != "1 0 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=-4, high=5. Expected 1 0 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[6] = {5, 3, 7, 2, 8, 6};
        for(int i = 0; i < 6; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(3,7);
        bst_str = bst2.to_string();
        if(bst_str != "5 3 7 6") {
            cout << "Incorrect tree after trimming 5 3 7 2 8 6 with low=3, high=7. Expected 5 3 7 6 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
    try {
        BST<string,string> bst;
        string vals[5] = {"apple", "banana", "cherry", "date", "fig"};
        for(int i = 0; i < 5; i++) {
            bst.insert(vals[i]+" data", vals[i]);
        }
        bst.trim("grape","kiwi");
        string bst_str = bst.to_string();
        if(bst_str != "") {
            cout << "Incorrect tree after trimming apple banana cherry date fig with low=grape, high=kiwi. Expected but got : " << bst_str << endl;
        }
        BST<string, string> bst2;
        string vals2[5] = {"cherry", "banana", "apple", "date", "fig"};
        for(int i = 0; i < 5; i++) {
            bst2.insert(vals2[i]+" data", vals2[i]);
        }
        bst2.trim("banana","date");
        bst_str = bst2.to_string();
        if(bst_str != "cherry banana date") {
            cout << "Incorrect tree after trimming cherry banana date apple fig with low=banana, high=date. Expected cherry banana date but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_binhex(){
    try {
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

        if(hex1!=expected_hex1) {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
        string bin2 = "110101";
        string expected_hex2 = "35";

        string hex2 = convert<string,string>(bst2, bin2);
        delete bst2;

        if(hex2!=expected_hex2) {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
      try {
        BST<string,string>* bst3 = create_bst<string,string>("binhex.txt");
        string bin3 = "0";
        string expected_hex3 = "0";

        string hex3 = convert<string,string>(bst3, bin3);
        
        if (hex3 != expected_hex3) {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }

        bin3 = "1111111";
        expected_hex3 = "7F";
        hex3 = convert<string,string>(bst3, bin3);
        
        if (hex3 != expected_hex3) {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }

        bin3 = "01110101100010111100000";
        expected_hex3 = "3AC5E0";
        hex3 = convert<string,string>(bst3, bin3);
        
        if (hex3 != expected_hex3) {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }        

        delete bst3;
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}


int main() {
    
    EmptyTests(); //done
    InsertTests(); //done
    GetTests(); //done
    RemoveTests(); //done
    MaxDataTests(); //done
    MaxKeyTests(); //done
    MinDataTests(); //done
    MinKeyTests(); //done
    SuccessorTests(); //done
    
    test_in_order(); //done
    cout << "Test In Order Done" << endl;
    test_trim();
    cout << "Test Trim Done" << endl;
    test_binhex();
    cout << "Test BinHex Done" << endl;

    cout << "Testing completed" << endl;
    
    return 0;
}
