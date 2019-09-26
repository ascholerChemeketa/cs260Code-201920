#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

void genNums(int arr[], int arrSize);


///------------------Quick Sort-----------------------------

//Postcondition: array is partitioned around some index p
//   such that for all i < p arr[i] <= A[p] and
//             for all j > p arr[j] >= A[p]
//  Returns index of p
int partitionFunct(int arr[], int low, int high) {
    //TODO - Fixme
    return 0;  //Delete this
}


void quickSortInternal (int arr[], int low, int high) {
    if (low >= high) return; // base case : 1 or less item

    //call partitionFunction to partition range low - high
    // it will return pivot location

    //recursively sort from low to pivot - 1
    //recursiely sort from pivot + 1 to high
}


void quickSort (int arr[], int arrSize) {
    quickSortInternal (arr, 0, arrSize-1);
}



///--------------No Need to Modify Below This Line -----------


//Fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    default_random_engine generator;
    generator.seed(static_cast<unsigned int>(time(nullptr)));  //sequence based on time
    //generator.seed(1);            //same sequence each time

    uniform_int_distribution<int> distribution(0,999999);

    for(int i = 0; i < arrSize; i++)
        arr[i] = distribution(generator);
}


int main()
{
    ///------------Function testing----------------
    cout << "Testing partition function:" << endl;
    int temp2[7]  = {12, 18, 3, 20, 6, 7, 15};
    cout << "Initial state : " << endl << " ";
    for(int i : temp2) cout << i << " ";
    cout << endl;
    int newPartLoc = partitionFunct(temp2, 0, 6);
    cout << "Partition returned location: " << newPartLoc << " which has value: " << temp2[newPartLoc] << endl;
    cout << " Verify all items to the left of that are smaller and all to the right are bigger" << endl;
    for(int i : temp2) cout << i << " ";
    cout << endl << endl;

    ///------------Actual sort testing----------------

    cout << endl << "Testing quickSort..." << endl;
    const int BIG_SIZE = 100000;

    int* bigNums = new int[BIG_SIZE];
    genNums(bigNums, BIG_SIZE);

    clock_t start= clock();
    quickSort(bigNums, BIG_SIZE);
    clock_t duration = clock() - start;

    if(std::is_sorted(bigNums, bigNums + BIG_SIZE)) {
        cout << "quickSort took: " << duration << endl;
    } else {
        cout << "quickSort failed!!" << endl;
    }

    return 0;
}

