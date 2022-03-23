/** myTests.cpp
 * 
 * Unit tests using Google Test
 * 
 * **/

#include <gtest/gtest.h> 
#include "maze.h"


/**
 * ----------------------------------------------------------------
 * User Story 1:
 * Find the empty space in a single-row input such as the following
 * ----------------------------------------------------------------
**/
TEST(storyOne, findTarget){

maze solver; 
std::string keyword = "empty";
bool passing = false; 

// Checking invalid tests
{
    std::vector<std::vector<int>> list = {{0, 0, 0, 0, 0, 0}};
    
    for (int i =0; i < list.size(); i++){
        for (int j=0; j < list[0].size(); j++){
            if (solver.isValidStep(list, list.size(), list[0].size(), i, j)){
            passing = true; 
            break; 
            }
        }
    }
    // no keyword found, should return false
    EXPECT_FALSE(passing); 
}

//valid test
{
    std::vector<std::vector<int>> list = {{0, 1, 0, 0, 0, 0}};

    for (int i =0; i < list.size(); i++){
        for (int j=0; j < list[0].size(); j++){
            if (solver.isValidStep(list, list.size(), list[0].size(), i, j)){
            passing = true; 
            break; 
            }
        }
    }
    EXPECT_TRUE(passing);
}

}


/**
 * ----------------------------------------------------------------
 * User Story 2: 
 * walk through a hallway in a maze
 * 2D maze 
 * no specfic solution asked other than "walk through hallway maze"
 * ----------------------------------------------------------------
**/
TEST(StoryTwo, walkHallway){

    // testing parameters for story two
    maze solver;
    // example maze given - hard coding input may not be ideal but in this situation we are provided input
    std::vector<std::vector<int>> maze = { 
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };
    // solution matrix that will have the valid path included
    std::vector<std::vector<int>> solPath = { 
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };


    // testing isValidStep() functionality 
    {
        int pathSize = 4; 
        int counter =0; 

        EXPECT_FALSE(pathSize == counter); 

        //nest for loop through all tiles in the maze and count number of "valid" tiles we expect
        for (int i=0; i<maze.size(); i++){
            for (int j=0; j<maze[i].size(); j++){
                bool sol = solver.isValidStep(maze, maze.size(), maze[i].size(), i, j);
                if (sol){
                    counter++;
                }
            }
        }
        EXPECT_EQ(pathSize, counter);
    }

    // testing backtracking, recursive algorithm to traverse maze and find path

    {
        EXPECT_FALSE(maze == solPath);

        if(solver.backtrack(maze, solPath, 0, 0)){
            EXPECT_EQ(maze, solPath);
        }

    }



}
