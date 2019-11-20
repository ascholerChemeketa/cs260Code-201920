#include "StringHashSet.h"

#include <cassert>
#include <algorithm>
#include <stdexcept>

using namespace std;

StringHashSet::StringHashSet(int numBuckets)
{
    setSize = 0;
    tableSize = numBuckets;
    buckets = new string[numBuckets];

    //We can count on strings bein initialized to "" which is our EMPTY_CELL value
    //    for(int i = 0; i < tableSize; i++)
    //        buckets[i] = EMPTY_CELL;
}

StringHashSet::~StringHashSet()
{
    delete [] buckets;
}


ostream& operator<<(ostream& os, const StringHashSet& theSet)
{
    os << "Buckets[ ";
    for(int i = 0; i < theSet.tableSize; i++) {
        if(theSet.buckets[i] == theSet.EMPTY_CELL)
            cout << "_ ";
        else if(theSet.buckets[i] == theSet.PREVIOUS_USED_CELL)
            cout << "# ";
        else
            cout << theSet.buckets[i] << " ";
    }
    os << "]";
    return os;
}



int StringHashSet::getBucket(string key) const {
    //get hashed value of string
    hash<string> hasher;
    unsigned int hashValue = hasher(key);  //technically type is size_t
    //return that mapped onto table
    return hashValue % tableSize;
}



bool StringHashSet::contains(string key) const {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

    int bucketNumber = getBucket(key);

    //look for the value starting in that bucket - need to keep searching until
    // we find an empty bucket
    while(buckets[bucketNumber] != EMPTY_CELL) {
        if( buckets[bucketNumber] == key )
            return true;

        //move to next bucket, wrap if necessary
        bucketNumber = (bucketNumber + 1) % tableSize;
    }

    return false;
}

void StringHashSet::insert(string key) {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

    if(contains(key))  //Nothing to do
        return;

    //grow if needed
    if(setSize > MAX_LOAD * tableSize)
        grow();

    //Find an empty or tombstoned location to place value in
    //  by starting at value returned from getBucket() and probing
    //  May need to wrap back to start of array
    //Otherwise, add at found location and increment size
}

void StringHashSet::remove(string key) {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid value");

    //Try to find item by starting at location given by getBucket() and probing
    // until item is found or we hit an empty cell
    // May need to wrap around

    //If found, decrements size and place a tombstone
}

int StringHashSet::size() const {
    return setSize;
}

void StringHashSet::grow() {
    //Make pointer to old array and store old tableSize

    //Set tableSize to tableSize * 2 + 1
    //Make new array; initialize all locations to EMPTY_CELL
    //Reset setSize to 0

    //For each value in old array that is not an empty or tombstone
    //  insert(value) back into data structure to force rehash

    //Delete old array
}
