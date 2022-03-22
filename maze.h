#ifndef MAZE_H
#define MAZE_H

#include <iostream>

class maze{

public:

    bool checkTarget(std::string currSpot, std::string target){
        if (currSpot == target){
            return true; 
        }
        return false; 
    }


};


#endif 