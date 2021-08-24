# Advanced Programming - Task 1

# Game engine

A simple commandline application that demonstrate my knowledge on OOP, 
Functional pointers and the use of time. 

The parent and child classes are both instantiated and passed through
the Add function of the dynamic instance of Game. 
After that, the game->Run() is called, which iterates through the passed in 
components and updates them 5 times by the second.

Game also contains a typedef named FP. This is invoked in main through the 
relevant Setters. The Init() and Term() methods are passed into these Setters, 
and they reside above the main() function.

The parent component is responsible to print the relevant IDs. Whilst the child
component hold the logic of how the component's motion is orchestrated.