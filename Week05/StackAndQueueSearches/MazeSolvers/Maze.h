#ifndef MAZE_H
#define MAZE_H


const int MAZE_SIZE = 10;

struct Maze {
    char cells[MAZE_SIZE][MAZE_SIZE] =
        {{'#','#','#','#',' ',' ','#','#','#','#'},
         {'#',' ',' ','#',' ',' ','#',' ',' ','#'},
         {'#',' ',' ','#',' ','#','#',' ','#','#'},
         {' ',' ','#','#',' ',' ',' ',' ',' ',' '},
         {' ','#','#',' ',' ',' ',' ','#','#','#'},
         {' ','#',' ',' ',' ',' ',' ','#',' ','#'},
         {' ','#',' ','#','#','#',' ','#',' ','#'},
         {' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
         {' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
         {' ',' ',' ','#','#','#','#','#','#','#'}};

    int startRow;
    int startCol;
    int goalRow;
    int goalCol;

    void printMaze() const;

    bool curLocationValid() const;

    bool atGoal() const;

    void markCurrent();

};


#endif // MAZE_H
