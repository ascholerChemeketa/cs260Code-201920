#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "StringHashSet.h"

using namespace std;

const int NUM_CHECKS = 1000000;

string makeRandomString() {
    string temp = "        ";
    for(int i = 0; i < 8; i++) {
        temp[i] = static_cast<char>('a' + rand() % 26);
    }
    return temp;
}


void testHashSet(int numItems) {
    StringHashSet s(10);

    //don't time filling with random data
    for(int i = 0; i < numItems; i++) {
        string randString = makeRandomString();
        s.insert(randString);
    }

    time_t start = clock();
    for(int i = 0; i < NUM_CHECKS; i++) {
        string randString = makeRandomString();
        s.contains(randString);
    }
    time_t duration = clock() - start;
    cout << " ...took " << duration << endl;
}


void simpleSetTest() {
    cout << std::boolalpha; //show bools as true/false

    StringHashSet s(8);    //set with 8 buckets

    cout << "Adding a, b, c, d..." << endl;

    if( s.getBucket("b") != s.getBucket("d") ) {
        cout << "WARNING - THIS WILL NOT CHECK YOUR TOMBSTONE" << endl;
        cout << "You need to replace 'd' in all the test code"  << endl;
        cout << "with something that collides with b"  << endl;
        cout << "--------------------------------------------" << endl;
    }

    s.insert("a");
    s.insert("b");
    s.insert("c");
    s.insert("d");

    cout << s << endl;

    cout << "Have a? " << s.contains("a") << endl;
    cout << "Have b? " << s.contains("b") << endl;
    cout << "Have d? " << s.contains("d") << endl;
    cout << "Have r? " << s.contains("r") << endl;

    cout << "Removing b. Should produce a tombstone" << endl;
    s.remove("b");
    cout << s << endl;

    cout << "Have a? " << s.contains("a") << endl;
    cout << "Have b? " << s.contains("b") << endl;
    cout << "Have d? " << s.contains("d") << endl;
    cout << "Have r? " << s.contains("r") << endl;


    cout << "Adding more letters... should force grow at some point" << endl;
    for(int i = 0; i < 10; i++) {
        string letter = " ";
        letter[0] = 'e' + i;
        s.insert(letter);
        cout << s << endl;
    }
}


int main()
{
    srand(time(0));

    cout << "Simple tests:" << endl;
    simpleSetTest();

    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;

    cout << "Timing tests:" << endl;
    for(int setSize = 10; setSize <= 1000000; setSize*=10) {
        cout << "Adding " << setSize << " strings and timing " << NUM_CHECKS << " lookups..." << endl;
        testHashSet(setSize);
    }


    return 0;
}
