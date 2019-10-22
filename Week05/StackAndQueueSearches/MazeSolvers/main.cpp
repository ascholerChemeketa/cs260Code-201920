#include <iostream>
#include <exception>
#include <cstdlib>
#include <deque>
#include <vector>

using namespace std;

#include "Maze.h"

typedef deque<Maze> mazeQueue;
typedef deque<Maze> mazeStack;

void findPathQueue(Maze& startMaze) {

    //maintain stack of paths to try
    mazeQueue pathsToTryQueue;
    pathsToTryQueue.push_back(startMaze);

    //as long as there are paths to try
    while(!pathsToTryQueue.empty()) {
        //Get the most recently found new path
        Maze curMaze = pathsToTryQueue.front();
        //Remove it from the queue
        pathsToTryQueue.pop_front();

        if(! curMaze.curLocationValid()) {
            continue; //dead end
        }

        //mark our copy with the move
        curMaze.markCurrent();
        curMaze.printMaze();

        if(curMaze.atGoal()) {
            //found it - can exit loop
            break;
        }

        //push all neighbors to stack
        Maze copy4 = curMaze;
        copy4.startRow++;
        pathsToTryQueue.push_back(copy4);  //down
        Maze copy3= curMaze;
        copy3.startRow--;
        pathsToTryQueue.push_back(copy3);  //up
        Maze copy2 = curMaze;
        copy2.startCol++;
        pathsToTryQueue.push_back(copy2);  //right
        Maze copy1 = curMaze;
        copy1.startCol--;
        pathsToTryQueue.push_back(copy1);  //left

    }
}



void findPathStack(Maze& startMaze) {

    //maintain stack of paths to try
    mazeStack pathsToTryStack;
    pathsToTryStack.push_back(startMaze);

    //as long as there are paths to try
    while(!pathsToTryStack.empty()) {
        //Get the most recently found new path
        Maze curMaze = pathsToTryStack.back();
        pathsToTryStack.pop_back();

        if(! curMaze.curLocationValid()) {
            continue; //dead end
        }

        //mark our copy with the move
        curMaze.markCurrent();
        curMaze.printMaze();

        if(curMaze.atGoal()) {
            //found it - can exit loop
            break;
        }

        //push all neighbors to stack
        Maze copy4 = curMaze;
        copy4.startRow++;
        pathsToTryStack.push_back(copy4);  //down
        Maze copy3= curMaze;
        copy3.startRow--;
        pathsToTryStack.push_back(copy3);  //up
        Maze copy2 = curMaze;
        copy2.startCol++;
        pathsToTryStack.push_back(copy2);  //right
        Maze copy1 = curMaze;
        copy1.startCol--;
        pathsToTryStack.push_back(copy1);  //left

    }
}



void findPathRecursive(Maze& curMaze) {
    if(! curMaze.curLocationValid()) {
        return; //dead end
    }

    //mark our copy with the move
    curMaze.markCurrent();
    curMaze.printMaze();

    if(curMaze.atGoal()) {
        //found it - throw exception to exit all recursion levels
        throw string("done");
    }

    Maze copy1 = curMaze;
    copy1.startCol--;
    findPathRecursive(copy1);  //left
    Maze copy2 = curMaze;
    copy2.startCol++;
    findPathRecursive(copy2);  //right
    Maze copy3= curMaze;
    copy3.startRow--;
    findPathRecursive(copy3);  //up
    Maze copy4 = curMaze;
    copy4.startRow++;
    findPathRecursive(copy4);  //down
}


int main()
{
    Maze theMaze;

    theMaze.printMaze();

    cout << "Enter start row & col with space between:" << endl;
    cout << "(Hint: 7 7 is fun)" << endl;
    cin >> theMaze.startRow >> theMaze.startCol;

    cout << "Enter destination row & col with space between:" << endl;
    cout << "(Hint: 5 5 is interesting to find from 7 7)" << endl;
    cin >> theMaze.goalRow >> theMaze.goalCol ;

    //recursive function throws an exception to stop
    // all recursion when a path is found.
    try {
        cout << "Recursive stack based search result:" << endl;
        cout << "Enter to continue...";
        cin.clear();
        cin.get();
        Maze mazeCopy1(theMaze);
        findPathRecursive(mazeCopy1);
    } catch (string& message) {
        //we are done
    }


    cout << "Stack based iterative search result:" << endl;
    cout << "Enter to continue...";
    cin.clear();
    cin.get();
    Maze mazeCopy2(theMaze);
    findPathStack(mazeCopy2);



    cout << "Queue based iterative search result:" << endl;
    cout << "Enter to continue...";
    cin.clear();
    cin.get();
    Maze mazeCopy3(theMaze);
    findPathQueue(mazeCopy3);

    return 0;
}
