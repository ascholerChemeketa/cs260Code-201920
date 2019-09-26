#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

#include "ArrayList.h"

using namespace std;

//get random num 0-99,999
int getRandom();

int main() {
    const int DATA_SIZE = 5000;

    clock_t start = clock();

    ArrayList<int> myList;
    for(int i = 0; i < DATA_SIZE; i++) {
        myList.insertEnd(getRandom());
    }

    clock_t duration = clock() - start;
    cout << fixed << setprecision(5);
    cout << "Took: " << (1.0 * duration / CLOCKS_PER_SEC) << " seconds" << endl;
    cout << "      ~" << (1.0 * duration / CLOCKS_PER_SEC)  / DATA_SIZE * 1000000000 << " ns per element" << endl;

    return 0;
}



//-----------------------------------------------------------------------
int getRandom() {
    //Reuse one generator and distribution object over lifetime of function:
    static default_random_engine generator(time(nullptr));
    static uniform_int_distribution<int> distribution(0,99999);

    //Use those to generate a new value
    return distribution(generator);
}
