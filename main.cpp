/** main.cpp 
 * 
 * Author: Eric Chheang
 * Date: 3/22/22
 * Purpose: Solutions to coding challenge by Path AI
 * 
 * **/
#include "myTests.cpp"



int main(int argc, char* argv[]){

    std::cout << std::endl 
    << "-------------------------------- PATH AI CODING CHALLENGE ---------------------------------- " <<
    std::endl << std::endl; 
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 



    return 0;
}