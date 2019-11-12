#include <iostream>
#include <algorithm>

using namespace std;


void printArray(int theArray[], int length) {
    for(int i = 0 ; i < length; i++)
        cout << theArray[i] << " ";
    cout << endl;
}

int leftChildIndex(int index) {
    return index * 2 + 1;
}

int rightChildIndex(int index) {
    return index * 2 + 2;
}


//Recursive heapify function
void maxHeapifyDown(int theArray[], int curIndex, int length) {

}

//Turns an array into a heap
void buildHeap(int theArray[], int length) {
    for(int i = length / 2; i >= 0; i--)
        maxHeapifyDown(theArray, i, length);
}

//Sort an array by turning into a heap and repeatedly removing the top
// item from the heap
void heapSort(int theArray[], int length) {

}

int main()
{
    int nums[] = {23, 9, 32, 6, 12, 25, 18};
    int numsSize = 7;

    buildHeap(nums, numsSize);

    //heapSort(nums, numsSize);

    printArray(nums, numsSize);


    return 0;
}
