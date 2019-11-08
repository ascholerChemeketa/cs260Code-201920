#include <iostream>

#include "MinHeap.h"

using namespace std;

int main()
{
    MinHeap m;

    cout << "---------------Building Heap---------------" << endl;
    for(int i = 50; i > 0; i-=5) {
        m.add(i);
        cout << m << endl;
    }

//    cout << "---------------Removing top five items---------------" << endl;
//    for(int i = 0; i < 5; i++) {
//        cout << "Removed " << m.removeTop() << endl;
//        cout << m << endl;
//    }


    return 0;
}
