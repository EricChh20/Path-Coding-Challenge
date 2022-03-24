#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stdio.h> 
#include <stack>
#include <queue> 

class maze{

public:


    /** checwks if x,y position is a valid step 
     * 
     * @param maze the 2D maze provided 
     * @param colSize x legnth of maze col 
     * @param rowSize y length of the maze row
     * @param curX current x position
     * @param curY current y position
     * @return true if valid, else false 
     * 
     *  **/
    bool isValidStep(const std::vector<std::vector<int>>& maze, int x, int y){

        if(x <= maze.size() && y <= maze[0].size() && maze[x][y] ==0){
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
     * 
     *  **/
    bool backtrack(std::vector<std::vector<int>> maze, std::vector<std::vector<int>> solPath, int curX, int curY){

        // check if current pos is end goal - making assumption we have beg/end
        if ((curX == maze.size()-1) && maze[curX][curY] == 0){
            solPath[curX][curY] = 0; 
            return true; 
        }
        // check if x,y is valid 
        if (isValidStep(maze, curX, curY)){
            //ignore if we have already stored as solution path
            if (solPath[curX][curY] == 1){
                return false;
            }
            //otherwise, add tile to solution path
            solPath[curX][curY] = 0; 
            //check block right of current pos
            if (backtrack(maze, solPath, curX+1, curY) == true){
                return true; 
            }
            // check block down of current pos
            if (backtrack(maze, solPath, curX, curY+1) == true){
                return true; 
            }
            // check block left of current pos
            if (backtrack(maze, solPath, curX-1, curY+1) == true){
                return true; 
            }
            // else we have to backtrack and remove pos as part of path 
            solPath[curX][curY] = 1;
            return false;
        }
        return false;
    }


    /** algorithm that uses a queue instead of recursion to find path through maze
     * 
     * @param maze 2D matrix representing our maze
     * @param start starting x,y position 
     * @param destination our exit or ending x,y position
     * @return true if we we found valid path from start to destination
     * 
     *  **/
    bool hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination) {
        int colSize = maze.size(), rowSize = maze[0].size();
        int d[] = {0, 1, 0, -1, 0};
        //queue to keep track of tiles to visit
        std::queue<std::vector<int>> todo;
        todo.push(start);
        //set visited tiles as -1 
        maze[start[0]][start[1]] = -1;

        while (!todo.empty()) {
            std::vector<int> p = todo.front();
            todo.pop();
            // check all four directions to see which way we can move
            for (int i = 0; i < 4; i++) {
                int col = p[0], row = p[1];
                //check which side is valid
                while (col + d[i] >= 0 && col + d[i] < colSize &&
                         row + d[i + 1] >= 0 && row + d[i + 1] < rowSize && 
                         maze[col + d[i]][row + d[i + 1]] <= 0) {

                    col += d[i];
                    row += d[i + 1];
                }
                //if we reached our target end tile, return
                if (col == destination[0] && row == destination[1]) {
                    return true;
                }
                if (!maze[col][row]) {
                    maze[col][row] = -1;
                    todo.push({col, row});
                }
            }
        }
        return false;
    }

    
};


#endif 