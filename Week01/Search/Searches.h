#ifndef SEARCHES_H
#define SEARCHES_H


//low and high represent the
//returns location of value or -1 if not present
int recursiveBinarySearchHelper(int value, int arr[], int low, int high);

//returns location of value or -1 if not present
int recursiveBinarySearch(int value, int arr[], int arrSize);

//returns location of value or -1 if not present
int binarySearch(int value, int arr[], int arrSize);


//pick number 1-1,000,000
int randomValue();

//fill array with random values 0-999,999
void genNums(int arr[], int arrSize);



#endif // SEARCHES_H
