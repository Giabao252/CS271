#include <iostream>
#include "set.cpp"
#include <string>
#include <sstream>

void test_insert() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<int> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
        }

        s.insert(2);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Cannot add duplicate element 2 to set " << set_str << endl;
        }

        Set<string> str;
        str.insert("apple");
        set_str = str.to_string();
        if (str.to_string() != "apple") {
            cout << "Incorrect insert result. Expected 'apple' but got: " << set_str << endl;
        }
        str.insert("banana");
        str.insert("watermelon");
        set_str = str.to_string();
        if (str.to_string() != "watermelon banana apple") {
            cout << "Incorrect insert result. Expected 'watermelon banana apple' but got: " << set_str << endl;
        }

        Set<char> c;
        c.insert('c');
        set_str = c.to_string();
        if (set_str != "c") {
            cout << "Incorrect insert result. Expected 'c' but got : " << set_str << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Insert method passed" << endl;
        }

    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());
        Set<string> s;
        s.insert("s");
        s.insert("r");
        s.insert("e");
        s.insert("t");
        s.insert("u");
        s.insert("p");
        s.insert("m");
        s.insert("o");
        s.insert("c");
        s.remove("s");
        string set_str = s.to_string();
        if (s.to_string() != "c o m p u t e r") {
            cout << "Incorrect remove result. Expected c o m p u t e r but got : " << set_str << endl;
        }
        s.remove("t");
        s.remove("e");
        s.remove("o");
        s.remove("r");
        s.remove("m");
        
        set_str = s.to_string();
        if(s.to_string() != "c p u") {
            cout << "Incorrect remove result. Expected c p u but got : " << set_str << endl;
        }

        Set<int> i;//7077
        i.insert(7);
        i.insert(0);
        i.insert(1);
        i.remove(7);
        set_str = i.to_string();
        if (i.to_string() != "1 0") {
            cout << "Incorrect remove result. Expected 1 0 but got : " << set_str << endl;
        }
        i.insert(10);
        i.insert(9);
        i.remove(1);
        set_str = i.to_string();
        if(i.to_string() != "9 10 0") {
            cout << "Incorrect remove result. Expected 9 10 0 but got : " << set_str << endl;
        }

        i.remove(1); //1 is not in the set
        if (i.to_string() != "9 10 0") {
            cout << "1 is not in the set. Expected 9 10 0 but got : " << set_str << endl;
        }

        Set<char> c;
        c.remove('3');
        string c_str = c.to_string();
        if (c.to_string() != "") {
            cout << "The set is empty. Expected an empty set but got " << c_str << endl;
        }
        c.insert('a');
        c.insert('b');
        c.insert('c');
        c.remove('c');
        c.remove('d');
        
        c_str = c.to_string();
        if (c.to_string() != "b a") {
            cout << "Incorrect remove result. Expected b a but got : " << c_str << endl;
        }
        c.remove(3);

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Remove method passed" << endl;
        } else {
            cout << "Remove method's test failed with error: " << buffer.str() << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(3);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }

        Set<string> i;
        c = i.cardinality();
        i.insert("s");
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 1 but got : " << c << endl;
        }
        i.insert("h");
        i.insert("t");
        i.insert("n");
        c = i.cardinality();
        if(c != 4) {
            cout << "Incorrect cardinality. Expected 4 but got : " << c << endl;
        }

        i.insert("k");
        i.insert("l");
        i.remove("s");
        c = i.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 7 but got : " << c << endl;
        }

        Set<char> j;
        c = j.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        j.insert('e');
        j.insert('r');
        j.insert('o');
        j.insert('t');
        c = j.cardinality();
        if(c != 4) {
            cout << "Incorrect cardinality. Expected 4 but got : " << c << endl;
        }
        j.remove('t');
        j.remove('o');
        j.remove('r');
    
        c = j.cardinality();
        if(c != 1) {
            cout << "Incorrect cardinality. Expected 1 but got : " << c << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Cardinality method passed" << endl;
        } else {
            cout << "Cardinality method's test failed with error: " << buffer.str() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<string> s;
        if(!(s.empty())){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert("r");
        s.insert("e");
        s.insert("s");
        s.insert("u");
        s.insert("h");

        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }

        s.remove("h");

        if(s.empty()) {//should be u s e r
            cout << "Non-empty set identified as empty" << endl;
        }
        
        s.remove("u");
        s.remove("s");
        s.remove("e");
        s.remove("r");

        if(!s.empty()) {//shoule be empty
            cout << "Empty set identified as non-empty" << endl;
        }

        Set<int> i;
        if(!i.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        i.insert(6);
        i.insert(1);
        i.insert(4);
        i.insert(3);
        i.insert(0);
        i.insert(1);
        i.insert(5);
        i.insert(9);

        if(i.empty()) {//should be 9 5 1 0 3 4 1 6
            cout << "Non-empty set identified as empty" << endl;
        }
        i.remove(6);
        i.remove(5);
        if(i.empty()) {// should be 9 1 0 3 4 1
            cout << "Non-empty set identified as empty" << endl;
        }
        i.remove(4);
        i.remove(9);
        if(i.empty()) {//should be 1031
            cout << "Non-empty set identified as empty" << endl;
        }

       Set<char> j;
        if(!j.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        j.insert('k');
        j.insert('n');
        j.insert('g');
        j.insert('o');
        if(j.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        j.remove('g');
        j.remove('o');
        if(j.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        j.remove('n');
        j.remove('k');
        if(!j.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        } 

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Empty method passed" << endl;
        } else {
            cout << "Empty method's test failed with error: " << buffer.str() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<string> str;
        if (str.contains("a")) {
            cout << "Incorrectly identified string a as in the set" << str.to_string() << endl;
        }
        str.insert("apple");
        str.insert("banana");
        
        if (!(str.contains("apple") && str.contains("banana"))) {
            cout << "Expected 'banana apple' but, instead, got " << str.to_string() << endl;
        }

        str.remove("apple");

        if (str.contains("apple")) {
            cout << "Incorrectly identified 'apple' as in the set " << str.to_string() << endl; 
        }
        str.remove("banana");

        if (str.contains("banana")) {
            cout << "Incorrectly identified 'banana' as in the set " << str.to_string() << endl; 
        }

        Set<int> s;
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }

        s.remove(3);

        if (s.contains(3)) {
            cout << "Incorrectly identified 3 as in the set " << str.to_string() << endl; 
        }
        s.remove(1);

        if (s.contains(1)) {
            cout << "Incorrectly identified 1 as in the set " << str.to_string() << endl; 
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Contains method passed" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<char> c1;
        Set<char> c2;

        if (!(c1==c2)) {
            cout << "Empty sets should be considered equal" << endl;
        }

        c1.insert('a');
        c1.insert('b');
        c1.insert('c');
        c1.insert('d');
        c1.insert('e');
        c2.insert('1');
        c2.insert('2');
        c2.insert('3');
        c2.insert('4');
        c2.insert('5');

        if (c1==c2) {
            cout << "Incorrectly identified set " << c1.to_string() << " as equivalent to empty set t " << c2.to_string() << endl;
        }

        c2.remove('1');
        c2.remove('2');
        c2.remove('3');
        c2.remove('4');
        c2.remove('5');
        c2.insert('a');
        c2.insert('b');
        c2.insert('c');
        c2.insert('d');
        c2.insert('e');

        if (!(c1==c2)) {
            cout << "Sets " << c1.to_string() << " and " << c2.to_string() << " should be considered equal." << endl;
        }
        Set<string> str1;
        Set<string> str2;
        if (!(str1==str2)) {
            cout << "Empty sets should be considered equal" << endl;
        }

        str1.insert("apple");
        if (str1 == str2) {
            cout << "Incorrectly identified set " << str1.to_string() << " as equivalent to empty set t " << str2.to_string() << endl;
        }

        str2.insert("banana");
        str1.remove("apple");
        if (str1 == str2) {
            cout << "Incorrectly identified set " << str1.to_string() << " as equivalent to empty set t " << str2.to_string() << endl;
        }

        str1.insert("watermelon");
        str1.insert("grape");
        str2.insert("apple");
        if (str1 == str2) {
            cout << "Incorrectly identified set " << str1.to_string() << " as equivalent to empty set t " << str2.to_string() << endl;
        }

        Set<string> str3;
        str3.insert("apple");
        str3.insert("banana");
        if (!(str2 == str3)) {
            cout << "Incorrectly identified set " << str1.to_string() << " as NOT equivalent to " << str2.to_string() << endl;
        }

        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to empty set t " << t.to_string() << endl;
        }
        t.insert(1);
        t.insert(2);
        t.insert(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.remove(3);
        t.remove(2);
        t.remove(1);
        if (s==t) {
            cout << "Incorrectly identifed set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Equality method passed" << endl;
        } else {
            cout << buffer.str() << endl;
        }

    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<char> c1;
        Set<char> c2;

        if(!(c1<=c2)) {
            cout << "Set " << c1.to_string() << " should be considered a subset of the set " << c2.to_string() << endl;
        }

        c1.insert('a');
        c1.insert('b');

        if (c1 <= c2 && !(c2 <= c1)) {
            cout << "Set " << c1.to_string() << " should be considered a subset of the set " << c2.to_string() << endl;
        }

        c2.insert('a');
        if (!(c2 <= c1)) {
            cout << "Set " << c1.to_string() << " should be considered a subset of the set " << c2.to_string() << endl;
        }

        c2.insert('b');
        if (!(c2 <= c1)) {
            cout << "Set " << c1.to_string() << " should be considered a subset of the set " << c2.to_string() << endl;
        }

        c2.insert('c');
        if (c1 <= c2 && c2 <= c1) {
            cout << "Set " << c1.to_string() << " should NOT be considered a subset of the set " << c2.to_string() << " and vice versa " << endl;
        }

        c1.remove('a');
        c1.remove('b');
        c1.insert('d');
        c1.insert('e');
        c2.insert('f');

        if (c1 <= c2 || c2 <= c1) {
            cout << "Set " << c1.to_string() << " should NOT be considered a subset of the set " << c2.to_string() << " and vice versa " << endl;
        }

        Set<string> str1;
        Set<string> str2;

        if(!(str1<=str2)) {
            cout << "Set " << str1.to_string() << " should be considered a subset of the set " << str2.to_string() << endl;
        }

        str1.insert("apple");
        str1.insert("banana");

        if (str1 <= str2 && !(str2 <= str1)) {
            cout << "Set " << str1.to_string() << " should be considered a subset of the set " << str2.to_string() << endl;
        }

        str2.insert("apple");
        if (!(str2 <= str1)) {
            cout << "Set " << str1.to_string() << " should be considered a subset of the set " << str2.to_string() << endl;
        }

        str2.insert("banana");
        if (!(str2 <= str1)) {
            cout << "Set " << str1.to_string() << " should be considered a subset of the set " << str2.to_string() << endl;
        }

        str2.insert("watermelon");
        if (str1 <= str2 && str2 <= str1) {
            cout << "Set " << str1.to_string() << " should NOT be considered a subset of the set " << str2.to_string() << " and vice versa " << endl;
        }

        
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(11);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Subset method passed" << endl;
        } else {
            cout << "Subset method's test failed with error " << buffer.str() << endl;
        }

    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<int> s;
        Set<int> t;
        string int_str = (s+t).to_string();
        if(int_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << int_str << endl;
        }
        s.insert(1);
        s.insert(2);
        int_str = (s+t).to_string();
        if (int_str != "1 2") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << int_str << endl;
        }

        t.insert(2);
        t.insert(1);
        int_str = (s+t).to_string();
        if(int_str != "2 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << int_str << endl;
        }
        t.insert(6);
        int_str = (s+t).to_string();
        if(int_str != "2 1 6") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << int_str << endl;
        }

        Set<string> str1;
        Set<string> str2;
        string set_str = (str1+str2).to_string();
        if (set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        str1.insert("apple");
        str1.insert("banana");
        str1.insert("watermelon");
        str2.insert("apple");
        str2.insert("banana");
        str2.insert("watermelon");

        set_str = (str1+str2).to_string();
        if (set_str != "apple banana watermelon") {
            cout << "Union of " << str1.to_string() << " and " << str2.to_string() << " was expected to be apple banana watermelon but instead got : " << set_str << endl;
        }

        str2.insert("grape");
        set_str = (str1+str2).to_string();
        if (set_str != "apple banana watermelon grape") {
            cout << "Union of " << str1.to_string() << " and " << str2.to_string() << " was expected to be apple banana watermelon grape but instead got : " << set_str << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Union method passed" << endl;
        } else {
            cout << "Union method's test failed with error " << buffer.str() << endl;
        }

    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<int> s;
        Set<int> t;
        string int_str = (s&t).to_string();

        Set<string> str1;
        Set<string> str2;
        
        string set_str = (str1&str2).to_string();
        if (set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        str1.insert("a");
        set_str = (str1&str2).to_string();
        if (set_str != "") {
            cout << "Intersection of the set " << str1.to_string() << " and " << str2.to_string() << " should be empty but instead got " << set_str << endl;
        }

        str2.insert("a");
        str2.insert("b");
        str2.insert("c");
        set_str = (str1&str2).to_string();
        if (set_str != "a") {
            cout << "Intersection of the set " << str1.to_string() << " and " << str2.to_string() << " should be 'a' but instead got " << set_str << endl;
        }

        str1.insert("b");
        str1.insert("c");
        set_str = (str1&str2).to_string();

        if (set_str != "a b c") {
            cout << "Intersection of the set " << str1.to_string() << " and " << str2.to_string() << " should be a b c but instead got " << set_str << endl;
        }


        //tests with type int
        int_str = (s&t).to_string();
        if(int_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << int_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        int_str = (s&t).to_string();
        if(int_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << int_str << endl;
        }
        t.insert(2);
        t.insert(1);
        int_str = (s&t).to_string();
        if(int_str != "1 2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << int_str << endl;
        }
        s.insert(6);
        int_str = (s&t).to_string();
        if (int_str != "1 2 6") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 6 but instead got : " << int_str << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Intersection method passed" << endl;
        } else {
            cout << "Intersection method's test failed with error: " << buffer.str() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        stringstream buffer;
        streambuf* old_cout = cout.rdbuf(buffer.rdbuf());

        Set<string> str1;
        Set<string> str2;
        string set_str = (str1-str2).to_string();
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        str1.insert("a");
        str1.insert("b");
        set_str = (str1-str2).to_string();
        if (set_str != "a b") {
            cout << "Set " << str1.to_string() << " \\ Set " << str2.to_string() << " was expected to be a b set but instead got : " << set_str << endl;
        }

        str2.insert("a");
        str2.insert("b");
        set_str = (str1-str2).to_string();
        if (set_str != "") {
            cout << "Difference of set " << str1.to_string() << " \\ set " << str2.to_string() << " should be the empty set. Instead got : " << set_str << endl;
        }

        Set<int> s;
        Set<int> t;
        string int_str = (s-t).to_string();
        if(int_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << int_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        int_str = (s-t).to_string();
        if(int_str != "1 2") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << int_str << endl;
        }
        t.insert(2);
        t.insert(1);
        int_str = (s-t).to_string();
        if(int_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << int_str << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty()) {
            cout << "Difference method passed" << endl;
        } else {
            cout << "Diffeence method's test failed with error: " << buffer.str() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> S;
    // TO-DO: generate large set
    Set<int> T;
    // TO-DO: generate large set
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}