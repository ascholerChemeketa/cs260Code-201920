#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

size_t myHash(string text) {
    unsigned int total = 0;
    //Mix in bits from each char after shifting existing pattern over 6 bits
    for(unsigned int i = 0; i < text.length(); i++)
        total = (total << 6) ^ text[i];
    return total;
}

struct Point {
    int x;
    int y;
};

size_t hashPoint(const Point& p) {
    //shift x's bits over 16 places and combine with y
    // guarantees 3, 2 is different than 2, 3
    return (p.x << 16) ^ p.y;
}

struct Person {
    string firstName;
    string lastName;
};

size_t hashPerson(const Person& p) {
    hash<string> stringHasher;

    //Combine the bits of hashed values of first and last name
    // no shift means John Smith will have same hash value as Smith John
    return stringHasher(p.firstName) ^ stringHasher(p.lastName);
}


int main() {
    vector<string> words = { "abc", "a", "apple", "bac", "cab", "cat", "dog"};

    cout << "-------------String hashing-------------" << endl;
    cout << "Custom hash function:" << endl;
    cout << setw(8) << "Word" << " : " << setw(10) << "Hash" << " : " << "Hash mod 11" << endl;
    for(string word : words)
        cout << setw(8) << word << " : " << setw(10) << myHash(word) << " : " << myHash(word)%11 << endl;

    cout << "std::hash<string>:" << endl;

    hash<string> stringHasher;
    cout << setw(8) << "Word" << " : " << setw(20) << "Hash" << " : " << "Hash mod 11" << endl;
    for(string word : words)
        cout << setw(8) << word << " : " << setw(20) << stringHasher(word) << " : " << stringHasher(word)%11 << endl;


    cout << "-------------String hashing-------------" << endl;


}
