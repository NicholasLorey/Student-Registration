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

#include "findIndex.h"
#include <stdio.h>
#include <string.h>

/******************************
 * Function name - findIndex
 * Purpose - to find the index of the student/course to be used later in modification of the table
 * Function In parameters - take the student/course array, the size and the target of the student id /course
 * Function Out parameters - it will return the index of student/course if found, else return -1
 * Student name - Nicholas Lorey
*******************************/
int findIndex(char** array, int size, char target[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(array[i], target) == 0) {
            return i; 
        }
    }
    return -1; 
}