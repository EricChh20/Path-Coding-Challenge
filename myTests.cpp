/** myTests.cpp
 * 
 * Unit tests using Google Test
 * 
 * **/

#include <gtest/gtest.h> 
#include "maze.h"


// user story 1 test cases 
TEST(storyOne, findTarget){

maze solver; 
std::string keyword = "empty";
bool passing = false; 

// Checking invalid tests
{
    std::vector<std::string> list = {"full", "full", "full", "full", "full", "full"};
    
    for (int i =0; i < list.size(); i++){
        if(solver.checkTarget(list[i], keyword)){
            passing = true; 
            break; 
        }
    }
    // no keyword found, should return false
    EXPECT_FALSE(passing); 
}

//valid test
{
    std::vector<std::string> list = {"full", "empty", "full", "full", "full", "full", "full"};

    for (int i =0; i < list.size(); i++){
        if(solver.checkTarget(list[i], keyword)){
            passing = true; 
            break; 
        }
    }
    EXPECT_TRUE(passing);
}

}

