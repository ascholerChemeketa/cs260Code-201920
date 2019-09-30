#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>  //for std::copy
#include <utility>      //for std::swap

using namespace std;


void insertionSort(int arr[], int arrSize) {
    //TODO - fixme
}

void selectionSort(int arr[], int arrSize) {
    //TODO - fixme
}


void bubbleSort(int arr[], int arrSize) {
    //n times
    for(int i = 1; i <= arrSize; i++) {
        //"bubble" from index 0 to n - i
        for(int j = 0; j < arrSize - i; j++) {
            if(arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

///--------------No Need to Modify This Section -----------

//fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    //the thing that generate pseudorandom bit patterns
    default_random_engine generator;
    generator.seed(time(nullptr));  //sequence based on time
    //generator.seed(1);            //same sequence each time

    //thing that interprets values as integers evenly distributed
    //over given range - inclusive of both ends
    uniform_int_distribution<int> distribution(0,999999);

    for(int i = 0; i < arrSize; i++)
        arr[i] = distribution(generator);

}

//Define sortFunctionType as a a pointer to function that
//   returns void, takes an array of int[] and an int
typedef  void (*sortFunctionType) (int[], int);


//Runs given sort function, verifies sort was performed
//  If sorted, prints time to sort. If not, prints failure message
void testSort(string functName, sortFunctionType sortFunct, int arr[], int arrSize) {
    clock_t start= clock();
    sortFunct(arr, arrSize);
    clock_t duration = clock() - start;

    if(std::is_sorted(arr, arr + arrSize)) {
        cout << functName << " took: " << duration << endl;
    } else {
        cout << functName << " failed!"<< endl;
    }
}
///-----------------------END SECTION-----------------------------


int main()
{
    const int SIZE = 10;

    //Create array and 2 copies
    int bigNums[SIZE];
    genNums(bigNums, SIZE);

    int bigCopy[SIZE];
    copy(bigNums, bigNums + SIZE, bigCopy);

    int bigCopy2[SIZE];
    copy(bigNums, bigNums + SIZE, bigCopy2);

    //Test all three sorts - testSort prints time to sort or error message
    testSort("Bubble", bubbleSort, bigCopy2, SIZE);
    testSort("Insertion", insertionSort, bigNums, SIZE);
    testSort("Selection", selectionSort, bigCopy, SIZE);

    cout << "Sorting the already sorted arrays..." << endl;
    testSort("Bubble", bubbleSort, bigCopy2, SIZE);
    testSort("Insertion", insertionSort, bigNums, SIZE);
    testSort("Selection", selectionSort, bigCopy, SIZE);

    return 0;
}
