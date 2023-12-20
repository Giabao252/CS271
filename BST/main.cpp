//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// main.cpp
// This file demonstrate the accuracy of usecase
//========================================================

#include <iostream>
#include "usecase.cpp"
#include "bst.cpp"
#include <string>
#include <sstream>
using namespace std;

bool check_bin(string s);

int main()
{
    BST<string, string> *bst = create_bst<string, string>("binhex.txt");

    string hex, bin;

    bin = "10100110";
    cout << "Convert from binary value 10100110 to hex value will give you: " << endl;
    hex = convert<string,string>(bst, bin);
    cout << "Hexidecimal representation of " << bin << " is " << hex << endl;

    string input_bin;
    
    cout << "----------------------------------------------------------" << endl;
    cout << "This is the part where you can try the conversion program." << endl;
    cout << "Enter binary representation for conversion: ";
    cin >> input_bin; // read binary value from terminal

    if (!check_bin(input_bin)) {
        cout << "Invalid binary value!" << endl;
    } 
    else {
        cout << "Hexidecimal representation of " << input_bin << " is " << convert<string,string>(bst, input_bin) << endl;
    }

    return 0;
}

//========================================================
// check_bin function
// pre-condition: an input string
// post-condition: a boolean value indicating if input is
// binary or not
// parameters: s: a string
// return: a boolean value
//========================================================
bool check_bin(string s)
{
    bool flag = true;
    int l = s.length(); // get length of s
    
    for(int i=0; i<l; i++) {
        // cout << s.at(i) << endl;
        if ((s.at(i) != '0') && (s.at(i) != '1')) {
            flag=false; // if s is not binary set flag to false
        }
    }
    
    return flag;
}