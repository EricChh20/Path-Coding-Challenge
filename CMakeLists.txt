cmake_minimum_required(VERSION 3.12)

project(codingChallenge) # name of project

add_subdirectory(googletest) 

include_directories(googletest/include) 

add_executable(myTests main.cpp) #add to executable 

target_link_libraries(myTests PUBLIC gtest) #link google test to this executable 

