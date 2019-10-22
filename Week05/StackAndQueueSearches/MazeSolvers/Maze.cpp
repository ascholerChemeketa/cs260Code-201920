#include <iostream>
#include <exception>

using namespace std;


#include "Maze.h"


void Maze::printMaze() const {
    //column headers
    cout << " ";
    for(int c = 0; c < MAZE_SIZE; c++)
        cout << c;
    cout << endl;

    for(int r = 0; r < MAZE_SIZE; r++) {
        cout << r;  //row header
        for(int c = 0; c < MAZE_SIZE; c++) {
            cout << cells[r][c] ;
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool Maze::curLocationValid() const {
    if(startRow < 0 || startCol < 0 || startRow >= MAZE_SIZE || startCol >= MAZE_SIZE)
    {
        return false;   //went out of bounds
    }
    if(cells[startRow][startCol] != ' ') {
        return false;   //hit wall/our existing path
    }
    return true;
}

bool Maze::atGoal() const {
    if(startRow == goalRow && startCol == goalCol)
        return true;
    else
        return false;
}

void Maze::markCurrent() {
    cells[startRow][startCol] = '.';
}
