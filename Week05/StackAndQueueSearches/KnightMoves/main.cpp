#include <iostream>
#include <vector>

#include "Queue.h"
#include "Location.h"

using namespace std;

///----------------------Vector helper functions-------------------------

void printVector(const vector<Location>& locList) {
    for(unsigned int i = 0; i < locList.size(); ++i) {
        cout << locList[i] << " ";
    }
    cout << endl;
}

std::ostream& operator<<(std::ostream& os, const vector<Location>& locList) {
    for(const Location& loc : locList)
        os << loc << " ";

    return os;
}

bool containsLocation(const vector<Location>& locList, const Location& loc) {
    for(unsigned int i = 0; i < locList.size(); ++i) {
        if(locList[i] == loc)
            return true;
    }
    return false;
}

vector<Location> getPossibleMoves(const Location& from) {
    vector<Location> possibleMoves;

    ///Ugly for loops generate each possible move for a knight
    //Can move up to -2 to +2 rows
    for(int rowMod = -2; rowMod <= 2; rowMod++) {
        if(rowMod == 0)
            continue;  //can't move 0 rows

        //Assume we move only 1 column. If we are moving just 1 row, move 2 cols
        int colsToMove = 1;
        if( rowMod == 1 || rowMod == -1 )
            colsToMove = 2;

        //Generate +/-1 col if moving 2 rows, +/-2 col if moving 1 row
        for(int colMod = -colsToMove; colMod <= colsToMove; colMod += 2 * colsToMove) {
            int newRow = from.row + rowMod;
            int newCol = from.col + colMod;

            //Only keep in bounds moves
            if( newRow >= 1 && newRow <= 8 &&
                newCol >= 1 && newCol <= 8)
            {
                possibleMoves.push_back(Location(newRow, newCol));
            }
        }
    }

    return possibleMoves;
}

///-------------------------------------------------------------------



int main()
{
    Location loc1(4, 4);            //starting location
    Location goalLocation(8, 8);    //goal location

    //Represent each possible path as a vector containing a series of locations
    // Initial path just has start location
    vector<Location> state1;     //starting state
    state1.push_back(loc1);

    //Initialize search storage - we are maintaing a queue that stores paths to explores
    //  Each path is a vector of Locations.
    Queue< vector<Location> > storage;
    storage.enqueue(state1);

    //List to keep track of Locations we already have seen - avoid cycles
    vector<Location> seenLocations;
    seenLocations.push_back(loc1);

    while( !storage.empty() ) {
        cout << "\n----------------------------------------" << endl;
        cout << "Seen locations: " << endl;
        printVector(seenLocations);
        cout << "States to process:" << endl;
        cout << storage << endl;

        //Get the next state to explore from the queue
        vector<Location> curPath = storage.dequeue();

        //The current location is the last item in vector
        Location curLocation = curPath.back();

        if(curLocation == goalLocation) {
            cout << "Found a path: " << curPath << endl;
            break;
        } else {
            cout << "Extending path: " << curPath << " --> ";
        }

        vector<Location> moves = getPossibleMoves(curLocation);

        for(Location& move : moves) {
            //Make sure we have not seen it
            if( !containsLocation(seenLocations, move) ) {

                //Make a new path that has the current path plus the new location
                vector<Location> newPath = curPath;
                newPath.push_back(move);
                storage.enqueue(newPath);

                cout << newPath << " ";

                //And location add to seen list
                seenLocations.push_back(move);
            }
        }
    }

}
