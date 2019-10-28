#include <iostream>
#include <exception>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

#include "Maze.h"

void findPathQueue(Maze& startMaze) {

    //maintain queue of paths to try
    queue<Maze> pathsToTryQueue;
    pathsToTryQueue.push(startMaze);

    //as long as there are paths to try
    while(!pathsToTryQueue.empty()) {
        //Get the most recently found new path
        Maze curMaze = pathsToTryQueue.front();
        //Remove it from the queue
        pathsToTryQueue.pop();

        if(!curMaze.curLocationValid()) {
            continue; //dead end
        }

        //mark our copy with the move
        curMaze.markCurrent();
        curMaze.printMaze();

        if(curMaze.atGoal()) {
            //found it - can exit loop
            break;
        }

        //add all neighbors to queue
        Maze copy1 = curMaze;
        copy1.startCol--;
        pathsToTryQueue.push(copy1);  //left
        Maze copy2 = curMaze;
        copy2.startCol++;
        pathsToTryQueue.push(copy2);  //right
        Maze copy3= curMaze;
        copy3.startRow--;
        pathsToTryQueue.push(copy3);  //up
        Maze copy4 = curMaze;
        copy4.startRow++;
        pathsToTryQueue.push(copy4);  //down
    }
}



void findPathStack(Maze& startMaze) {

    //maintain stack of paths to try
    stack<Maze> pathsToTryStack;
    pathsToTryStack.push(startMaze);

    //as long as there are paths to try
    while(!pathsToTryStack.empty()) {
        //Get the most recently found new path
        Maze curMaze = pathsToTryStack.top();
        pathsToTryStack.pop();

        if(!curMaze.curLocationValid()) {
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
        pathsToTryStack.push(copy4);  //down
        Maze copy3= curMaze;
        copy3.startRow--;
        pathsToTryStack.push(copy3);  //up
        Maze copy2 = curMaze;
        copy2.startCol++;
        pathsToTryStack.push(copy2);  //right
        Maze copy1 = curMaze;
        copy1.startCol--;
        pathsToTryStack.push(copy1);  //left

    }
}



void findPathRecursive(Maze& curMaze, bool& isDone) {
    if(!curMaze.curLocationValid() || isDone) {
        return; //Either a dead end, or we already
                //found a solution on some other recursive call
    }

    //mark our copy with the move
    curMaze.markCurrent();
    curMaze.printMaze();

    if(curMaze.atGoal()) {
        curMaze.printMaze();
        isDone = true;
    }

    Maze copy1 = curMaze;
    copy1.startCol--;
    findPathRecursive(copy1, isDone);  //left
    Maze copy2 = curMaze;
    copy2.startCol++;
    findPathRecursive(copy2, isDone);  //right
    Maze copy3= curMaze;
    copy3.startRow--;
    findPathRecursive(copy3, isDone);  //up
    Maze copy4 = curMaze;
    copy4.startRow++;
    findPathRecursive(copy4, isDone);  //down
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


    Maze mazeCopy1(theMaze);
    bool found = false;
    findPathRecursive(mazeCopy1, found);


    cout << "Stack based iterative search result:" << endl;
    cout << "Enter to continue...";
    cin.ignore(256, '\n');
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
