# Path-Coding-Challenge

Author: Eric Chheang 
Date: 3/23/2022
Purpose: Coding challenge from Path Robotics

### Table of Contents 
- Introduction  
- Getting Started: Setting up, Building, Executing  
- Project Reflection/Analysis  

  

### Description of Solution
The purpose of this Repo is to provide a solution to the Path Robotic's Code Kata - Maze coding challenge.  
The following instructions should allow you to clone, set up, build, and run the program and it's unit tests.  

<br />


## Getting Started

### Setting up

- Clone this repo
```shell
git clone https://github.com/EricChh20/Path-Coding-Challenge.git 
```

- Clone Google Test Repo 
```shell
git clone https://github.com/google/googletest.git
```

### Building 

- Create and move inside build folder
```shell
mkdir build
cd build
```

- Run the following
```shell
cmake .. 
make 
```
### Execute Program/Tests
```shell
./myTests
```
<br />
<br />
### Resulting execution: 
<img width="668" alt="Screen Shot 2022-03-23 at 11 36 29 PM" src="https://user-images.githubusercontent.com/42673389/159837443-7cdbeaf5-2c32-40e7-b979-e7a076319525.png">
<br />
<br />

## Reflection/Analysis 
  
### Part 1 Coding 

1. User Story 1: Find "empty" space in a single-row input 
2. User Story 2: Walk through a "hallway" maze such as 
3. User Story 3: Find a way into and out of rooms such as
4. User Story 4: Find winding paths
5. User Story 5: Reach end of maze, even if dead ends


<br />
<br />

### Part 2 Analysis

1. Analysis Story 1   
At this point, you may have created a general-purpose solver. If not, try to identify some types of mazes that your algorithm would not solve correctly. 

- As I progressed through the user stories and different types of mazes, it became obvious that my initial solution was very naive and not an effective general solver. My solution was an algorithm that solved what was specifically asked of me and is very limited to those constraints. 
- The User Story 1 solver would have struggled with many other "mazes" and edge cases, below are some example: 
  - The solver only takes in a specific data type for the "maze", assuming all mazes would be an array of strings.  
    This would fail any problem that is created specifically for this solver, not a good general design. 
  - It would not have solved a 2D matrix such as the other mazes in the challenge. 
  - It requires user input for a specific "keyword" to find within the "maze". 

  
  <br />

  
2. Analysis Story 2 
If you kept things simple, it is likely that your algorithm may not be as efficient as possible. Describe the solution’s complexity and approaches that could be used to optimize it further. 

- As I was working through user story 2, I decided to implement a recursive backtracking algorithm. This is not the most efficient algorithm to deploy because it is esentially a DFS approach where it has to check the entire matrix. In my specific implementation, it is even worse in terms of space complexity because I wanted to keep track of the solution path so I had to create another solutions matrix for that. 

  - Time Complexity: When using DFS, the big O of traversing an adjacency matrix like this maze would O(V^2), with being the number of nodes. In short, we are traversing to each node, checking to see if we have visited, then moving on to the adjacent node. So, while this technically "solves" the problem, it would not be ideal with a larger tree to have to search. 

  - Space Complexity: In typical DFS, the space complexity would involve a data structure like a stack which could, at worse, hold all the nodes in the graph. Therefore it would be O(V). In my implementation, I used a 2D matrix to create a replica of the maze with a "solution" drawn out on it. 
 
 
- In my later implementation, I went with a BFS algorithm utilizing queues instead of recursive DFS. Also, it can be noted that we no longer need a "visited" array to track our movements by having the visited space be -1 and our check being <= 0. This is more efficient and would bring the time complexity to O(nm) and space complexity to O(nm), with n and m being the dimensions of the matrix (maze). 
  
 <br />

  
3. Analysis Story 3 
Moving robots isn’t as simple as moving a 1x1 pixel through a maze. Instead, we must plan a path while avoiding obstacles using a collision model. We can approximate this by plotting a path for a 1x3 “ship” through a maze. In addition to moving “backward” and “forward” the ship can also rotate around its center of gravity provided it is in the center of a 3x3 
Do not code a solution, but instead describe an approach for decomposing this problem into incremental stories as done for the maze problem above. 

- Since we do not have all the infomation on this problem, some assumptions will have to be made on the desired solution and constraints. The first step would be gather as much input from stake holders and leads as possible before considering a solution. 

  - Step 1: Clarifying questions: 
    - are there specific time or space constraints that we have to consider? If this were to deploy on hardward, I'd imagine there would be potential storage, processing capabilities, or time contraints that we have to consider. 
    - We would need to understand how the robot is "sensing" and what types of inputs it is feeding our algorith.  
    - 

  - Step 2: High-level design: 
    - With the following inputs, design a high-level approach to solving it and break it down into incremental stesp. 
      - Robot "plans" a path to avoid obsacles using this collision model. 
      - This robot with it's collision model can be represented as a 1x3 object. 
      - Movements: forward, backwards, and rotation if in the center of a 3x3 "block". 

    - With those inputs, we will have 3 incremental tasks to tackle this problem: 
      - decide on most efficient searching algorithm based on our time and space constraints. 
      - create a general maze solver with our decided algorithm. 
        - This could be an exsisting algorithm such as DFS, BFS, A* or a custom one with specific hueristics.
        - Test algorithm through unit tests on funcitonality and handling specific inputs from sensors. 
      - adjust parameters and functionality to account for a 1x3 size movements within the maze. 
        - the 1x3 size and "rotation" functionality should be able to easily be added to our exsisting system. 
        - test the new algorithm on the same unit and integration testing performed on our prev solver. 
      - the final and probably most important task would be final testing. 
        - this would include the unit and integration testing, alongside our software-in-the-loop and hardware-in-the-loop testing process to ensure this solution truely solves the solution as a robust and efficient solver. 


        
