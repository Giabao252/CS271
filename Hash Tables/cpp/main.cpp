#include <iostream>
#include <string>
#include "usecase.cpp"
#include "element.cpp"
#include "hash_table.cpp"

using namespace std;

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

int main() {
    test_login();
    cout << "Testing completed" << endl;
    
    return 0;
}
