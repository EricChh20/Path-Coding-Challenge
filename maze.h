#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stdio.h> 

class maze{

public:


    /** checks if x,y position is a valid step 
     * 
     * @param maze the 2D maze provided 
     * @param colSize x legnth of maze col 
     * @param rowSize y length of the maze row
     * @param curX current x position
     * @param curY current y position
     * @return true if valid, else false 
     * 
     *  **/
    bool isValidStep(std::vector<std::vector<int>> maze, int colSize, int rowSize, int curX, int curY){

        if(curX <= colSize && curY <= rowSize && maze[curX][curY] ==1){
                return true; 
            }
        return false; 
    }

    /** utility function that uses a recursive algorithm to traverse through "maze"
     * 
     * @param maze 2D matrix to represent maze consisting of ints as valid/non-valid states
     * @param solPath 2D solution matrix outlining solution path 
     * @param curX current x-position in maze
     * @param curY current y-position in maze
     * @return true if one of conditions are met
     *  **/
    bool backtrack(std::vector<std::vector<int>> maze, std::vector<std::vector<int>> solPath, int curX, int curY){

        // check if current pos is end goal - making assumption we have beg/end
        if ((curX == maze.size()-1) && maze[curX][curY] == 1){
            solPath[curX][curY] = 1; 
            return true; 
        }
        // check if x,y is valid 
        if (isValidStep(maze, maze.size(), maze[0].size(), curX, curY)){
            //ignore if we have already stored as solution path
            if (solPath[curX][curY] == 1){
                return false;
            }
            //otherwise, add tile to solution path
            solPath[curX][curY] = 1; 
            //move forward
            // use of recursive function
            if (backtrack(maze, solPath, curX+1, curY) == true){
                return true; 
            }
            // if x isnt solution, go y direction 
            if (backtrack(maze, solPath, curX, curY+1) == true){
                return true; 
            }
            // else we have to backtrack and remove pos as part of path 
            solPath[curX][curY] = 0;
            return false;
        }
        return false;
    }

    /** function that calls maze-solving utility function
     * @param maze 2D matrix representing maze
     * @param solPath 2D matrix for the solution path found
     * @return true if sucessfully finds solution path
     * 
     * **/
    bool solveMaze(std::vector<std::vector<int>> maze, std::vector<std::vector<int>> solPath){
        if (backtrack(maze, solPath, 0, 0) == false){
            return false;
        }
        return true; 

    }



};


#endif 