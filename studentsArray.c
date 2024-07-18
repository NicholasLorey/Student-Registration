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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentsArray.h"

/******************************
 * Function name - students_array
 * Purpose - to create an array that contain student id
 * Function In parameters - to take the total of student that user want to input
 * Function Out parameters - to return a 2d char array memory location for each student id
 * Student name - Nicholas Lorey
*******************************/
char **students_array(int size){
    int i,length;
    int checkError;
    char** array;
    char* ptr;
    char digit[] = "0123456789";
    /*allocate the memory for the array*/

    array = malloc(size*sizeof(char*));   

    for(i = 0; i < size; i++){
        array[i] = malloc(6*sizeof(char));
        
    }
    for(i = 0; i < size;i++){
        do{
            printf("Enter the student index[%d] student id [5-digits]:",i);
            checkError = scanf("%s",array[i]);
            while (getchar() != '\n');
            length = strlen(array[i]);

            ptr = strpbrk(array[i], digit);
            if(length != 5 || ptr == NULL){
                printf("Student ID must be 5 digit\n");
            }
            
        }while(checkError == 0 || length !=5 || ptr == NULL);     
        
    }

    

    
    return array;
}