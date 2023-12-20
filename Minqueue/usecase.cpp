//========================================================
// Linh Mai, Bao Luu, Jeremiah Shelton
// CS271, Fall 2023
// usecase.cpp
// This file contains uses of the MinQueue class to solve the sliding window problem
//========================================================

#include <string>
#include <iomanip>
#include "minqueue.cpp"
using namespace std;

//=================================================
// sliding_window
// creates a string of minimum values from a sliding window in a given array
// PARAMETERS:
// arr: given array
// len: the length of the array
// window: the visible window of elements from which to find the minimum
// RETURN VALUE:
// arr_1: string of minimum values from all windows
//=================================================
template <typename T>
string sliding_window(T arr[], int len, int window)
{

    string arr_1 = ""; // string that store answer
    if (len == 0 || window == 0 || window > len) {
        return "";
    }
    if (window > len)  // if window is greater than the entire array, take min of entire array
    {
        MinQueue<T> mq(arr, len);
        arr_1 = to_string(mq.min());
        return arr_1;
    }
    for (int i = 0; i + window <= len; i++) // for loop to create subarrays of length window
    {
        T subarr[window]; // subarray
        int a = 0;
        for (int j = i; j < window + i; j++) // copy values from main array to subarray
        {
            subarr[a] = arr[j];
            a++;
        }
        MinQueue<T> mq1(subarr, window); // create minqueue from subarray
        arr_1 += to_string(mq1.min());   // add minimum value to answer string
        if (i + window != len)           // add space if not the final member
        {
            arr_1 += " ";
        }
    }
    return arr_1;
}
