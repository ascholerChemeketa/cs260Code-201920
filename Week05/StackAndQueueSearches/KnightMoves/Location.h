#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

struct Location {
    int row;
    int col;

    Location() {
        row = 0;
        col = 0;
    }

    Location(int r, int c) {
        row = r;
        col = c;
    }

    bool operator==(const Location& other) const {
        return row == other.row && col == other.col;
    }
};

std::ostream& operator<<(std::ostream& os, const Location& aLocation);

#endif // LOCATION_H
