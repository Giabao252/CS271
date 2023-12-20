//
//  test_hashtable_example.cpp
//  CS 271 Hash Table Project: Example Test File
//
//  Created by Dr. Stacey Truex
//

#include <iostream>
#include <sstream>
#include "usecase.cpp"
#include "element.cpp"
#include "hash_table.cpp"

using namespace std;

void test_get_key()
{
    try
    {
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        Element<int> empty_elem;
        if (empty_elem.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty_elem.get_key() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }

        Element<string> empty1;
        if (empty1.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty1.get_key() << endl;
        }

        Element<string> str_e("test", 9);
        if (str_e.get_key() != 9)
        {
            cout << "Incorrect result from get key. Expected 1 but got : " << str_e.get_key() << endl;
        }

        Element<char> char_e('i', 2);
        if (char_e.get_key() != 2)
        {
            cout << "Incorrect result from get key. Expected 2 but got : " << char_e.get_key() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "get_key method passed" << endl;
        }
        else
        {
            cout << "get_key method's test failed with error: " << buffer.str() << endl;
        }
    }

    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data()
{
    try
    {
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        Element<int> empty_elem;
        if (empty_elem.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << empty_elem.get_data() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got : " << e.get_data() << endl;
        }
        Element<string> str_empty;
        if (str_empty.get_data() != "")
        {
            cout << "Incorrect result from get data. Expected "
                    " for an empty element but got : "
                 << str_empty.get_data() << endl;
        }
        Element<string> str_e("banana", 9);
        if (str_e.get_data() != "banana")
        {
            cout << "Incorrect result from get data. Expected banana but got : " << str_e.get_data() << endl;
        }
        Element<char> char_empty;
        if (char_empty.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << char_empty.get_data() << endl;
        }
        Element<char> char_e('b', 5);
        if (char_e.get_data() != 'b')
        {
            cout << "Incorrect result from get data. Expected b but got : " << char_e.get_data() << endl;
        }
        Element<float> float_e(8.5, 3);
        if (float_e.get_data() != 8.5)
        {
            cout << "Incorrect result from get data. Expected 8.5 but got : " << float_e.get_data() << endl;
        }
        Element<long> long_empty;
        if (long_empty.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << long_empty.get_data() << endl;
        }
        Element<long> long_e(1234567891, 4);
        if (long_e.get_data() != 1234567891)
        {
            cout << "Incorrect result from get data. Expected 1234567891 but got : " << long_e.get_data() << endl;
        }
        Element<double> double_empty;
        if (double_empty.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << double_empty.get_data() << endl;
        }
        Element<double> double_e(12345.234, 11);
        if (double_e.get_data() != 12345.234)
        {
            cout << "Incorrect result from get data. Expected 12345.234 but got : " << double_e.get_data() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "get_data method passed" << endl;
        }
        else
        {
            cout << "get_data method's test failed with error: " << buffer.str() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }

        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected0: \n1: (1,21) (10,6) \n2: \n3: \n4: \nBut got\n\n" << ht.to_string() << endl;
        }

        HashTable<string> str_empty(0);
        str_empty.insert("apple", 6);
        if (str_empty.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << str_empty.to_string() << endl;
        }
        HashTable<string> ht_str(6);
        ht_str.insert("banana", 3);
        if (ht_str.to_string() != "0: \n1: \n2: \n3: (banana,3) \n4: \n5: \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: (banana,3) \n4: \n5: \nBut got\n\n" << ht_str.to_string() << endl;
        }
        ht_str.insert("watermelon", 4);
        if (ht_str.to_string() != "0: \n1: \n2: \n3: (banana,3) \n4: (watermelon,4) \n5: \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: (banana,3) \n4: (watermelon,4) \n5: \nBut got\n\n" << ht_str.to_string() << endl;
        }

        HashTable<char> char_empty(0);
        char_empty.insert('a', 6);
        if (char_empty.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << char_empty.to_string() << endl;
        }
        HashTable<char> ht_char(6);
        ht_char.insert('a', 2);
        if (ht_char.to_string() != "0: \n1: \n2: (a,2) \n3: \n4: \n5: \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (a,2) \n3: \n4: \n5: \nBut got\n\n" << ht_char.to_string() << endl;
        }
        ht_char.insert('b', 3);
        ht_char.insert('c', 1);
        if (ht_char.to_string() != "0: \n1: (c,1) \n2: (a,2) \n3: (b,3) \n4: \n5: \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (c,1) \n2: (a,2) \n3: (b,3) \n4: \n5: \nBut got\n\n" << ht_char.to_string() << endl;
        }
        HashTable<float> float_empty(0);
        float_empty.insert(0.45, 6);
        if (float_empty.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << float_empty.to_string() << endl;
        }
        HashTable<float> ht_float(6);
        ht_float.insert(0.4, 2);
        ht_float.insert(9.8, 3);
        if (ht_float.to_string() != "0: \n1: \n2: (0.4,2) \n3: (9.8,3) \n4: \n5: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (0.4,2) \n3: (9.8,3) \n4: \n5: \nBut got\n\n" << ht_float.to_string() << endl;
        }

        HashTable<long> long_empty(0);
        float_empty.insert(-9876543, 6);
        if (float_empty.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << float_empty.to_string() << endl;
        }
        HashTable<long> ht_long(6);
        ht_long.insert(-9876543210L, 5);
        ht_long.insert(8765410L, 2);
        if (ht_long.to_string() != "0: \n1: \n2: (8765410,2) \n3: \n4: \n5: (-9876543210,5) \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (8765410,2) \n3: \n4: \n5: (-9876543210,5) \nBut got\n\n" << ht_long.to_string() << endl;
        }

        HashTable<double> double_empty(0);
        double_empty.insert(3255432.5430, 8);
        if (double_empty.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << double_empty.to_string() << endl;
        }
        HashTable<double> ht_double(6);
        ht_double.insert(100.011, 0);
        if (ht_double.to_string() != "0: (100.011,0) \n1: \n2: \n3: \n4: \n5: \n")
        { 
            cout << "Incorrect result of inserting into table. Expected\n\n0: (100.011,0) \n1: \n2: \n3: \n4: \n5: \nBut got\n\n" << ht_double.to_string() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "insert method passed" << endl;
        }
        else
        {
            cout << "insert method's test failed with error: " << buffer.str() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
        HashTable<int> ht1(5);
        ht1.insert(101, 6);
        ht1.remove(5);
        if (ht1.to_string() != "0: \n1: (101,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (101,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht1.to_string() << endl;
        }
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }

        HashTable<string> str_empty(0);
        str_empty.remove(6);
        if (str_empty.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << str_empty.to_string() << endl;
        }
        HashTable<string> ht_str(5);
        ht_str.insert("apple", 5);
        ht_str.remove(5);
        if (ht_str.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }

        HashTable<char> char_empty(0);
        char_empty.remove(6);
        if (char_empty.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << char_empty.to_string() << endl;
        }
        HashTable<char> ht_char(5);
        ht_char.insert('a', 2);
        ht_char.insert('b', 4);
        ht_char.remove(2);
        if (ht_char.to_string() != "0: \n1: \n2: \n3: \n4: (b,4) \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: (b,4) \n\nBut got\n\n" << ht_char.to_string() << endl;
        }

        HashTable<long> long_empty(0);
        long_empty.remove(6);
        if (long_empty.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << long_empty.to_string() << endl;
        }
        HashTable<long> ht_long(5);
        ht_long.insert(548973542, 1);
        ht_long.insert(7895466,4);
        ht_long.remove(4);
        if (ht_long.to_string() != "0: \n1: (548973542,1) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (548973542,1) \n2: \n3: \n4: \n\nBut got\n\n" << ht_long.to_string() << endl;
        }

        HashTable<float> float_empty(0);
        float_empty.remove(6);
        if (float_empty.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << float_empty.to_string() << endl;
        }
        HashTable<float> ht_float(5);
        ht_float.insert(54.2, 3);
        ht_float.insert(8.01, 2);
        ht_float.remove(3);
        ht_float.remove(2);
        if (ht_float.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }
        
        HashTable<double> double_empty(0);
        double_empty.remove(6);
        if (double_empty.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << double_empty.to_string() << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "remove method passed" << endl;
        }
        else
        {
            cout << "remove method's test failed with error: " << buffer.str() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from table : " << e.what() << endl;
    }
}

void test_member()
{
    try
    {
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.member(11, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht.member(10, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<string> empty_str(0);
        if (empty_str.member("test", 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<string> ht_str(5);
        ht_str.insert("apple", 6);
        if (ht_str.member("banana", 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht_str.member("apple", 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<char> empty_char(0);
        if (empty_char.member('a', 4))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<char> ht_char(5);
        ht_char.insert('b', 6);
        ht_char.insert('d', 0);
        if (ht_char.member('c', 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if ((!ht_char.member('b', 6)) && (!ht_char.member('d',0)))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<float> empty_float(0);
        if (empty_float.member(10.01, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<float> ht_float(5);
        ht_float.insert(10.01, 6);
        ht_float.insert(1.1,1);
        if (ht_float.member(11.1, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if ((!ht_float.member(10.01, 6)) && (!ht_float.member(1.1,1)))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<long> empty_long(0);
        if (empty_long.member(10545432, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<long> ht_long(5);
        ht_long.insert(1765746580, 6);
        if (ht_long.member(116455, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht_long.member(1765746580, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<double> empty_double(0);
        if (empty_double.member(10243.1, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }

        HashTable<double> ht_double(5);
        ht_double.insert(10432.12, 6);
        if (ht_double.member(11, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht_double.member(10432.12, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "member method passed" << endl;
        }
        else
        {
            cout << "member method's test failed with error: " << buffer.str() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to determine membership in table : " << e.what() << endl;
    }
}

void test_login()
{
    try
    {   
        stringstream buffer;
        streambuf *old_cout = cout.rdbuf(buffer.rdbuf());

        HashTable<string> *ht = create_table<string>("logins.csv", 10);
        string username = "IEv";
        string password = "7170790290";
        if (!login(ht, username, password))
        {
            cout << "Incorrect result validating accurate login information" << endl;
        }
        username = "bad-user";
        password = "98213873";
        if (login(ht, username, password))
        {
            cout << "Incorrect result validating inaccurate login information" << endl;
        }

        cout.rdbuf(old_cout);

        // Check if anything was printed to cout
        if (buffer.str().empty())
        {
            cout << "login passed" << endl;
        }
        else
        {
            cout << "login test failed with error: " << buffer.str() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in accomplishing login validation : " << e.what() << endl;
    }
}

int main()
{
    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();
    test_login();

    cout << "Testing completed" << endl;

    return 0;
}