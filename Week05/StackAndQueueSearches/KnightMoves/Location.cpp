#include "Location.h"


std::ostream& operator<<(std::ostream& os, const Location& aLocation) {
    os << "(" << aLocation.row << "," << aLocation.col << ")";
    return os;
}
