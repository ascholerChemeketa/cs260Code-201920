#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Searches.h"

int main()
{
    //Seed the rng for random generation
    srand(static_cast<int>(time(0)));

    //----------------------Correctness Test------------------------
	int smallNumsSize = 8;
	int smallNums[] = {1, 3, 6, 8, 12, 13, 15, 17};

	cout << "Testing with smallNums:" << endl;
	for(int i = 0; i < 20; i++) {
        int loc = binarySearch(i, smallNums, smallNumsSize);
		cout << i << " is at: " << loc << endl;
	}

    //----------------Test timing with Large Numbers----------------
    const int BIGNUM_SIZE = 1000;
    int* bigNums = new int[BIGNUM_SIZE];

    //Fill with random numbers and sort
    genNums(bigNums, BIGNUM_SIZE);

    //Do some searching
    int TIMING_REPS = 1;
    clock_t start = clock();
    for(int i = 0; i < TIMING_REPS; i++) {
        binarySearch(randomValue(), bigNums, BIGNUM_SIZE);
    }
    clock_t end = clock();

    cout << "Took "
         << (end - start) * 1.0 / CLOCKS_PER_SEC / TIMING_REPS
         << endl;

    return 0;
}
