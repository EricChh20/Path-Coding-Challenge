#ifndef MAZE_H
#define MAZE_H

#include <iostream>

class maze{

public:

    /** Checks if current value matches our target 
     * @param currSpot The value at the current index 
     * @param target keyword target we are searching for
     * @return true or false 
     * 
     * **/

    bool checkTarget(std::string currSpot, std::string target){
        if (currSpot == target){
            return true; 
        }
        return false; 
    }


};


#endif 