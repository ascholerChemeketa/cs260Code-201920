#ifndef HASHSET_H
#define HASHSET_H

#include <string>
#include <iostream>

class StringHashSet
{
    private:
        int tableSize;
        int setSize;
        std::string* buckets;
        const double MAX_LOAD = 0.7;

        //value used to indicate a cell is empty - cannot be stored in set
        const std::string EMPTY_CELL = "";
        //value used to indicate a cell is empty but once had a value
        const std::string PREVIOUS_USED_CELL = "#";

        //reallocate new storage array
        void grow();

    public:
        StringHashSet(int numBuckets);

        bool contains(std::string key) const;
        void insert(std::string key);
        void remove(std::string key);
        int size() const;

        //Memory management
        virtual ~StringHashSet();
        //Copy ctor and assignment operator declared but not defined to prevent default versions
        StringHashSet(const StringHashSet& other);
        StringHashSet& operator=(const StringHashSet& other);

        //Printing
        friend std::ostream& operator<<(std::ostream& os, const StringHashSet& theSet);

        //Determine bucket given items should be in
        int getBucket(std::string key) const;
};

#endif // HASHSET_H
