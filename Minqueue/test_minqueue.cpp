//
//  test_minqueue_example.cpp
//  Priority Queue Project
//
//  Created by Stacey Truex
//
#include <iostream>
#include <string>
#include "usecase.cpp"

using namespace std;

void test_minqueue() {
    float* float_data = new float[10];
    char* char_data = new char[10];
    int* int_data = new int[20];
    for(int i = 0; i < 20; i++){
        int_data[i] = 20-i;
    }
    float arr[10] = {1.8, 1.9, 1.3, 1.2, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5};
    char arr1[10] = {'c', 'd', 'a', 'f', 'g', 'h', 'k', 'l', 't', 'o'};
    for (int i = 0; i < 10; i++) {
        float_data[i] = arr[i];
        char_data[i] = arr1[i];
    }
    try {

        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 20);
        mq_str = mq.to_string();
        if(mq_str != "1 2 6 3 10 8 7 4 12 11 19 9 15 18 14 5 13 17 20 16") {
            cout << "Incorrect result from empty constructor. Expected 1 2 6 3 10 8 7 4 12 11 19 9 15 18 14 5 13 17 20 16 but got : " << mq_str << endl;
        }

        MinQueue<float> float_arr(float_data, 10);
        string mq_str1 = float_arr.to_string();

        if(mq_str1 != "1.2 1.7 1.3 1.9 1.8 12.8 20.9 56.2 23.8 10.5") {
            cout << "Incorrect result from empty constructor. Expected 1.2 1.7 1.3 1.9 1.8 12.8 20.9 56.2 23.8 10.5 but got : " << mq_str1 << endl;
        }

        MinQueue<char> char_arr(char_data, 10);
        string mq_str2 = char_arr.to_string();

        if(mq_str2 != "a d c f g h k l t o") {
            cout << "Incorrect result from empty constructor. Expected a d c f g h k l t o but got : " << mq_str2 << endl;
        }

    } catch (exception& e) {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
}


void test_insert() {
    
    float* float_data = new float[11];
    char* char_data = new char[11];
    int* int_data = new int[19];
    for(int i = 0; i < 19; i++) {
        int_data[i] = 19+i;
    }
    int int_data1[11] = {0,1,4,3,2,5,8,10,7,9,6};
    float arr[10] = {1.8, 1.9, 1.3, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    char arr1[11] = {'q', 't', 'b', 'f', 'g', 'h', 'k', 'l', 'r', 'o', 'i'};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        char_data[i] = arr1[i];
    }

    try {

        MinQueue<int> empty;
        empty.insert(0);
        empty.insert(10);
        string mq_str = empty.to_string();

        if(mq_str != "0 10") {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data1, 11);
        mq.insert(25);
        string mq_str1 = mq.to_string();

        if(mq_str1 != "0 1 4 3 2 5 8 10 7 9 6 25") {
            cout << "Incorrect insert result. Expected 0 1 4 3 2 5 8 10 7 9 6 25 but got : " << mq_str1 << endl;
        }
        
        MinQueue<float> float_arr(float_data, 11);
        float_arr.insert(2.9);
        string float_str = float_arr.to_string();
        if(float_str != "0 1.7 1.3 1.8 1.9 2.9 56.2 23.8 10.5 100.202 12.8 20.9") {
            cout << "Incorrect insert result. Expected 0.9 1.7 1.2 1.9 1.8 1.3 20.9 56.2 23.8 10.5 100.202 12.8 but got : " << float_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }
    delete[] float_data;
    delete[] char_data;
    delete[] int_data;
    
   
}

void test_min() {
    float* float_data = new float[11];
    char* char_data = new char[11];
    int* int_data = new int[19];
    for(int i = 0; i < 19; i++) {
        int_data[i] = 19-i;
    }
    float arr[11] = {1.8, 1.9, 1.3, 1.0, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    char arr1[11] = {'q', 't', 'b', 'f', 'g', 'h', 'k', 'l', 'r', 'o', 'i'};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        char_data[i] = arr1[i];
    }

    try {

        MinQueue<int> empty;
        int min = empty.min();
        if(min != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<int> mq(int_data, 19);
        min = mq.min();
        if(min != 1) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<float> mq1(float_data, 11);
        float min_float = mq1.min();
        if(min_float != 1.0) {
            cout << "Incorrect min result. Expect 1.2 but got : " << min_float << endl;
        }

        MinQueue<char> mq2(char_data, 11);
        char min_char = mq2.min();
        if(min_char != 'b') {
            cout << "Incorrect min result. Expect b but got : " << min_char << endl;
        }

    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
    delete[] float_data;
    delete[] char_data;
    delete[] int_data;
}

void test_extract_min() {
    char* char_data = new char[11];
    float* float_data = new float[11];
    string* str_data = new string[11];
    int* int_data = new int[19];
    for(int i = 0; i < 19; i++) {
        int_data[i] = i;
    }
    float arr[11] = {1.8, 1.9, 1.3, 1.0, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    string arr1[11] = {"sort", "heap", "john", "banger", "chicken", "water", "ciao", "chao", "hello", "banana", "apple"};
    char arr2[11] = {'q', 't', 'b', 'f', 'g', 'h', 'k', 'l', 'r', 'o', 'i'};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        str_data[i] = arr1[i];
        char_data[i] = arr2[i];
    }

    try {

        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();

        if(min != 0 || mq_str != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<int> mq0(int_data, 19);
        min = mq0.extract_min();
        mq_str = mq0.to_string();

        if(min != 0 || mq_str != "1 3 2 7 4 5 6 15 8 9 10 11 12 13 14 18 16 17") {
            cout << "Incorrect extract min result. Expected 0 and the queue 1 3 2 7 4 5 6 15 8 9 10 11 12 13 14 18 16 17 but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<float> mq1(float_data, 11);
        float min_float = mq1.extract_min();
        mq_str = mq1.to_string();
        if(min_float != 1.0 || mq_str != "1.3 1.7 12.8 1.9 1.8 100.202 20.9 56.2 23.8 10.5") {
            cout << "Incorrect extract min result. Expected 1.0 and the queue 1.3 1.7 12.8 1.9 1.8 100.202 20.9 56.2 23.8 10.5 but got : " << min_float << " and a queue of : " << mq_str << endl;
        }

        MinQueue<char> mq2(char_data, 11);
        char min_char = mq2.extract_min();
        mq_str = mq2.to_string();
        if(min_char != 'b' || mq_str != "f g h l i q k t r o") {
            cout << "Incorrect extract min result. Expected b and the queue f g h l i q k t r o but got : " << min_char << " and a queue of : " << mq_str << endl;
        }

        MinQueue<string> mq3(str_data, 11);
        string min_string = mq3.extract_min();
        mq_str = mq3.to_string();
        if(min_string != "apple" || mq_str != "banana banger ciao chao chicken water john sort hello heap") {
            cout << "Incorrect extract min result. Expected apple and the queue banana banger ciao chao chicken water john sort hello heap but got : " << min_string << " and a queue of : " << mq_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
    delete[] float_data;
    delete[] str_data;
    delete[] int_data;
    delete[] char_data;
}

void test_decrease_key()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
        {
            cout << "Incorrect decrease key result. Expected -6 -1 4 3 2 5 8 10 7 6 but got : " << mq_str << endl;
        }

        // test decrease key
        MinQueue<int> mq1(int_data, 1);
        mq1.decrease_key(1, -6);
        mq1.decrease_key(-5, 1);
        mq1.decrease_key(0, 30);
        mq_str = mq1.to_string();
        if (mq_str != "10")
        {
            cout << "Incorrect decrease key result. Expected unchanged queue for invalid arguments but got : " << mq_str << endl;
        }

        mq1.decrease_key(0, -3);
        mq_str = mq1.to_string();
        if (mq_str != "-3")
        {
            cout << "Incorrect decrease key result. Expected a queue of -3 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapify() {

    int* empty_data = new int[0];
    float* float_data = new float[11];
    char* char_data = new char[11];
    int* int_data = new int[17];
    for(int i = 0; i < 17; i++){
        int_data[i] = i;
    }
    float arr[11] = {1.8, 1.9, 1.3, 1.0, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    char arr1[11] = {'q', 't', 'b', 'f', 'g', 'h', 'k', 'l', 'r', 'o', 'i'};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        char_data[i] = arr1[i];
    }

    try {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 17);
        string o_mq_str = mq.to_string();
        mq.set(1, 90);
        mq.min_heapify(1);
        
        mq_str = mq.to_string();
        
        if(mq_str != "0 3 2 7 4 5 6 15 8 9 10 11 12 13 14 90 16") {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 0 3 2 7 4 5 6 15 8 9 10 11 12 13 14 90 16 but got : " << mq_str << endl;
        }

        MinQueue<float> mq1(float_data, 11);
        string initial_float = mq1.to_string();
        mq1.set(7, 50.0);
        mq1.set(4, 3.03);
        mq1.min_heapify(7);
        mq1.min_heapify(4); 

        mq_str = mq1.to_string();
        
        if(mq_str != "1 1.7 1.3 1.9 3.03 12.8 20.9 50 23.8 10.5 100.202") {
            cout << "Incorrect heapify result in heapifying index 4 and 7 in the minqueue " << initial_float << " after setting to 3.03 and 50.0. Expected 1 1.7 1.3 1.9 3.03 12.8 20.9 50 23.8 10.5 100.202 but got : " << mq_str << endl;
        }

        MinQueue<char> mq2(char_data, 11);
        string initial_char = mq2.to_string();
        mq2.set(11, 'a');
        mq2.set(1, 'w');
        mq2.min_heapify(11);
        mq2.min_heapify(1); 

        mq_str = mq2.to_string();
        
        if(mq_str != "b g h l i q k t r o w") {
            cout << "Incorrect heapify result in heapifying index 11 and 1 in the minqueue " << initial_char << " after setting to 3.03 and 50.0. Expected b g h l i q k t r o w but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
}

void test_build_min_heap(){
    float* float_data = new float[11];
    char* char_data = new char[11];
    int* int_data = new int[19];
    for(int i = 0; i < 19; i++) {
        int_data[i] = 19+i;
    }
    float arr[11] = {1.8, 1.9, 1.3, 1.2, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    char arr1[11] = {'q', 't', 'b', 'f', 'g', 'h', 'k', 'l', 'r', 'o', 'i'};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        char_data[i] = arr1[i];
    }

    try {

        MinQueue<int> mq;
        mq.allocate(19);
        for(int i = 0; i < 19; i++) {
            mq.set(i, int_data[i]);
        }
        string o_mq_str = mq.to_string();
        mq.build_heap();
        string mq_str = mq.to_string();

        if(mq_str != "19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37") {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 but got : " << mq_str << endl;
        }

        MinQueue<float> mq1;
        mq1.allocate(11);
        for(int i = 0; i < 11; i++) {
            mq1.set(i, float_data[i]);
        }
        string initial_float = mq1.to_string();
        mq1.build_heap();
        mq_str = mq1.to_string();

        if(mq_str != "1.2 1.7 1.3 1.9 1.8 12.8 20.9 56.2 23.8 10.5 100.202") {
            cout << "Incorrect build_heap result from " << initial_float << ". Expected 1.2 1.7 1.3 1.9 1.8 12.8 20.9 56.2 23.8 10.5 100.202 but got : " << mq_str << endl;
        }

        MinQueue<char> mq2;
        mq2.allocate(11);
        for(int i = 0; i < 11; i++) {
            mq2.set(i, char_data[i]);
        }
        string initial_char = mq2.to_string();
        mq2.build_heap();
        mq_str = mq2.to_string();

        if(mq_str != "b f h l g q k t r o i") {
            cout << "Incorrect build_heap result from " << initial_char << ". Expected b f h l g q k t r o i but got : " << mq_str << endl;
        }

    } catch (exception &e) {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;
    delete[] float_data;
    delete[] char_data;
}

void test_heapsort() {
    float* float_data = new float[11];
    string* str_data = new string[11];
    int* empty_data = new int[0];
    float arr[11] = {1.8, 1.9, 1.3, 1.2, 1.7, 12.8, 20.9, 56.2, 23.8, 10.5, 100.202};
    string arr1[11] = {"sort", "heap", "john", "banger", "chicken", "water", "ciao", "chao", "hello", "banana", "apple"};
    for (int i = 0; i < 11; i++) {
        float_data[i] = arr[i];
        str_data[i] = arr1[i];
    }
    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = i;
    }

    try {

        MinQueue<int> heap0(int_data, 10);
        heap0.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if(sorted_str != "0 1 2 3 4 5 6 7 8 9") {
            cout << "Incorrect heapsort result. Expected 0 1 2 3 4 5 6 7 8 9 but got : " << sorted_str << endl;
        }

        MinQueue<float> heap1(float_data, 11);
        heap1.sort(float_data);

        string sorted_float = to_string(float_data[0]);

        for(int i = 1; i < 11; i++) {
            sorted_float += (" " + to_string(float_data[i]));
        }

        if(sorted_float != "1.200000 1.300000 1.700000 1.800000 1.900000 10.500000 12.800000 20.900000 23.799999 56.200001 100.202003") {
            cout << "Incorrect heapsort result. Expected 1.200000 1.300000 1.700000 1.800000 1.900000 10.500000 12.800000 20.900000 23.799999 56.200001 100.20200 but got : " << sorted_float << endl;
        }

        MinQueue<string> heap2(str_data, 11);
        heap2.sort(str_data);

        string sorted_string = str_data[0];

        for(int i = 1; i < 11; i++) {
            sorted_string += (" " + str_data[i]);
        }

        if(sorted_string != "apple banana banger chao chicken ciao heap hello john sort water") {
            cout << "Incorrect heapsort result. Expected apple banana banger chao chicken ciao heap hello john sort water but got : " << sorted_string << endl;
        }

    } catch (exception& e) {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
    delete[] float_data;
    delete[] str_data;
}

void test_sliding_window() {

    int* empty = new int[0];
    int nums[8] = {1,3,-1,-3,5,3,6,7};

    int* empty_1 = new int[0];
    int nums_1[12] = {1,5,9,12,6,7,2,5,9,8,4,7};

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

    } catch(exception &e) {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

try {

        string window_result_1 = sliding_window(empty_1, 0, 0);

        if(window_result_1 != "") {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result_1 << endl;
        }



        window_result_1 = sliding_window(nums_1, 12, 4);

        if(window_result_1 != "1 5 6 2 2 2 2 4 4") {
            cout << "Incorrect sliding window result. Expected 1 5 6 2 2 2 2 4 but got : " << window_result_1 << endl;
        }

        window_result_1 = sliding_window(nums_1 ,7, 1);

        if(window_result_1 != "1 5 9 12 6 7 2") {
            cout << "Incorrect sliding window result. Expected 1 5 9 12 6 7 2 but got : " << window_result_1 << endl;
        }

    } catch(exception &e) {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

    delete[] empty;
}


void time_test() {
    MinQueue<int> mq;
    // TO-DO: generate large minqueue
    int size = -1;  // TO-DO: set size of large minqueue
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    int _ = mq.min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    _ = mq.extract_min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    int last_index = size - 1; // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    
    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapify();
    test_build_min_heap();
    test_heapsort();
    
    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
