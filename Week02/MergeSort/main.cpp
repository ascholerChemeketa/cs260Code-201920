#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>
#include <utility>

using namespace std;


///------------------Merge Sort-----------------------------
//Precondition: arr contains two sorted sequences:
//   one begins at low and ends at mid
//   other begins at mid+1 and ends at high
//Postcondition: sequences are merged into one
//   sorted sequence spanning from low to high
void mergeFunc(int arr[], int low, int mid, int high, int temp[]) {
    //TODO - Fixme

    //Set up i (first half location), j (second half location),
    //   and k (location in temp)

    //While first half is not empty and second half not empty
    //  Decide if first or second half has next smallest item
    //  Move it it temp

    //While first half is not empty
    //  Move next item from it to temp

    //While second half is not empty
    //  Move next item from it to temp

    //Copy indexes from low-high from temp back to arr
}

//Recursive helper for mergesort
void mergeSortInternal (int arr[], int low, int high, int temp[]) {
    //TODO - Fixme
    if (low >= high)
        return; /* base case: 1 or fewer elements */

    int mid;
    //Set mid to halfway between low and high
    //Recursively sort first low to mid
    //Recursively sort second mid+1 to high

    mergeFunc(arr, low, mid, high, temp); /* merge two halves using temp */
}

//Sorts an array of integers of given size
//    allocates n extra storage and calls helper
void mergeSort(int arr[], int arrSize) {
    int* temp = new int[arrSize];
    mergeSortInternal (arr, 0, arrSize-1, temp);
    delete [] temp;
}




///--------------No Need to Modify Below This Line -----------

//Fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    default_random_engine generator;
    generator.seed(time(nullptr));  //sequence based on time
    //generator.seed(1);            //same sequence each time

    uniform_int_distribution<int> distribution(0,999999);

    for(int i = 0; i < arrSize; i++)
        arr[i] = distribution(generator);
}


int main()
{
    ///------------Function testing----------------
    int temp[7];
    cout << "Testing merge function - should produce completely sorted list" << endl;
    int mergeTest1[]  = {1,8,10,20,6,7,15};
    mergeFunc(mergeTest1, 0, 3, 6, temp);
    for(int i : mergeTest1)
        cout << i << " ";
    cout << endl;
    if(!std::is_sorted(mergeTest1, mergeTest1 + 7))
        cout << "Failed!!" << endl;

    cout << endl << "Testing merge function - should sort everything from index 2-5" << endl;
    cout << "(999 represents item that should not move)" << endl;
    int mergeTest2[]  = {999,999,4,8,3,12,999};
    mergeFunc(mergeTest2, 2, 3, 5, temp);
    for(int i : mergeTest2)
        cout << i << " ";
    cout << endl;
    if(!std::is_sorted(mergeTest2 + 2, mergeTest2 + 5))
        cout << "Failed!!" << endl;


    ///------------Actual sort testing----------------

    cout << endl << "Testing mergeSort..." << endl;
    const int BIG_SIZE = 100000;

    int* bigNums = new int[BIG_SIZE];
    genNums(bigNums, BIG_SIZE);

    clock_t start= clock();
    mergeSort(bigNums, BIG_SIZE);
    clock_t duration = clock() - start;

    if(std::is_sorted(bigNums, bigNums + BIG_SIZE)) {
        cout << "MergeSort took: " << duration << endl;
    } else {
        cout << "MergeSort failed!!" << endl;
    }

    return 0;
}

