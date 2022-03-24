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
bool passing = false; 

// Checking invalid tests
{
    std::vector<std::vector<int>> list = {{1, 1, 1, 1, 1, 1}};
    
    for (int i =0; i < list.size(); i++){
        for (int j=0; j < list[0].size(); j++){
            if (solver.isValidStep(list, i, j)){
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
    std::vector<std::vector<int>> list = {{1, 0, 1, 1, 1, 1}};

    for (int i =0; i < list.size(); i++){
        for (int j=0; j < list[0].size(); j++){
            if (solver.isValidStep(list, i, j)){
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
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    // solution matrix that will have the valid path included
    std::vector<std::vector<int>> solPath = { 
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

    // testing isValidStep() functionality 
    {
        int pathSize = 4; 
        int counter =0; 

        EXPECT_FALSE(pathSize == counter); 
        //nest for loop through all tiles in the maze and count number of "valid" tiles we expect
        for (int i=0; i<maze.size(); i++){
            for (int j=0; j<maze[i].size(); j++){
                bool sol = solver.isValidStep(maze, i, j);
                if (sol){
                    counter++;
                }
            }
        }
        EXPECT_EQ(pathSize, counter);
    }

    // testing backtracking, recursive algorithm to traverse maze and find valid path
    {
        EXPECT_FALSE(maze == solPath);
        if(solver.backtrack(maze, solPath, 0, 0)){
            EXPECT_EQ(maze, solPath);
        }
    }
    //tested new maze solver with 2nd maze
    {
        std::vector<int> start = {0,2};
        std::vector<int> dest = {3,2};
        EXPECT_TRUE(solver.hasPath(maze, start, dest));
    }

}

/**
 * ----------------------------------------------------------------
 * User Story 3: 
 * find way into and out of rooms
 * 2D maze 
 * looks like we may need a more effificent solver than previous recusion
 * ----------------------------------------------------------------
**/

TEST(StoryThree, bfsMaze){

    // testing parameters for story 3
    maze solver;
    // example maze given - hard coding input may not be ideal but in this situation we are provided input

    // test bad start/dest input
    {
        std::vector<std::vector<int>> maze3 = { 
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
        };
        // failing with invalid start, dest values
        std::vector<int> start = {-2, 5};
        std::vector<int> dest = {1, 5};
        EXPECT_FALSE(solver.hasPath(maze3, start, dest));
    }
    // sucessfull 
    {
        std::vector<std::vector<int>> maze3 = { 
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
        };
        // sucessfull start and dest 
        std::vector<int> start = {0,1};
        std::vector<int> dest = {3,3};

        EXPECT_TRUE(solver.hasPath(maze3, start, dest));
    }
}

/**
 * ----------------------------------------------------------------
 * User Story 4: 
 * Follow winding paths
 * - at this point, we are looking to test our maze solver with more complex maze patterns
 * ----------------------------------------------------------------
**/

TEST(UserStory4, mazeTest){

maze solver; 
//expected failure due to bad inputs
{
    std::vector<std::vector<int>> maze = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
    };
    std::vector<int> start = {0, 1};
    std::vector<int> dest = {6, 4};

    EXPECT_FALSE(solver.hasPath(maze, start, dest));

}

//sucessful path with correct inputs
{
    std::vector<std::vector<int>> maze = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
    };
    std::vector<int> start = {0, 1};
    std::vector<int> dest = {6, 3};

    EXPECT_TRUE(solver.hasPath(maze, start, dest));

}

}
