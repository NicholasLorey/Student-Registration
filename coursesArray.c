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
#include "coursesArray.h"

/******************************
 * Function name - courses_array
 * Purpose - to create an array that contain courses
 * Function In parameters - to take the total of course user want to input
 * Function Out parameters - to return a 2d char array memory location for each course
 * Student name - Nicholas Lorey
*******************************/
char **courses_array(int size){
    int i,length;
    char** array;
    char* ptr, * ptr1;
    char alphas[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char digit[5];
    char alpha[4];

    array = malloc(size*sizeof(char*));   

    for(i = 0; i < size; i++){
        array[i] = malloc(8*sizeof(char));
        
    }
    for(i = 0; i < size;i++){
        do{
            printf("Enter the course index[%d] course id [3-alphas][4-digits]:",i);
            scanf("%s",array[i]);
            while (getchar() != '\n');

            strncpy(alpha, array[i],3);
            alpha[3] = '\0';

            strncpy(digit, array[i]+3,4);
            digit[4] = '\0';

            ptr = strpbrk(alpha, digits);
            ptr1 = strpbrk(digit, alphas);
            
            length = strlen(array[i]);

            if(length != 7){
                printf("Incorrect Course Id length [7-character Id]\n");
            }else if(ptr != NULL || ptr1 != NULL){
                printf("Incorrect Course Id input [3-alphas][4-digits]\n");
            }
            
        }while(length !=7 || ptr != NULL || ptr1 != NULL);     
        
    }


    
    return array;
}