#include "usecase.cpp"
#include <iostream>
#include <string>

using namespace std;

void test_sliding_window() {

    int* empty = new int[0];
    int nums[8] = {1,3,-1,-3,5,3,6,7};

    try {

        string window_result = sliding_window(empty, 0, 0);

        if(window_result != "") {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 8, 3);

        if(window_result != "-1 -3 -3 -3 3 3") {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 1, 1);

        if(window_result != "1") {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }


        //test sliding window
        window_result = sliding_window(nums, 6, 2);
        if(window_result != "1 -1 -3 -3 3") {
            cout << "Incorrect sliding window result. Expected 1 -1 -3 -3 3 but got : " << window_result << endl;
        }
        

    } catch(exception &e) {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

    delete[] empty;
}
int main()
{
    test_sliding_window();
    cout << "Testing Complete";
    return 0;
}
