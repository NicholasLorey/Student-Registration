/******************************
 * Student Name: Nicholas Lorey
 * Student Number: 041101536
 * Assignment number: Assignment_01
 * Course name: CST_8234_310
 * Lab section number: 311
 * Professor's name: Daniel Cormier
 * Due date of assignment: 7 July 2024
 * Submission date of assignment: 6 July 2024
 * 
*******************************/

#include "mallocR.h"
#include <stdio.h>
#include <stdlib.h>

/******************************
 * Function name - toMalloc
 * Purpose - to memory allocation for the register table
 * Function In parameters - take the register array, the student size and the course size to be memory allocate
 * Function Out parameters - it will return the register table array
 * Student name - Nicholas Lorey
*******************************/
int **toMalloc(int** registerTab, int studentSize, int courseSize){
    int i;
    int rowSize = studentSize*courseSize;
    registerTab = malloc(rowSize*sizeof(int)+((rowSize*3)*sizeof(int)));
    for(i = 0; i < rowSize; i++){
        registerTab[i] = malloc(3*sizeof(int));
        
    }
    return registerTab;
}