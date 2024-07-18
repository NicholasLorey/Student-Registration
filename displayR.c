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

#include "displayR.h"
#include <stdio.h>

/******************************
 * Function name - displayTable
 * Purpose - to display the register table array that has been created
 * Function In parameters - take the register table, course table, and student table
 * Function Out parameters - it print the formated table where student register/drop
 * Student name - Nicholas Lorey
*******************************/
void displayTable(int** registerTab,char** studentArr, char** courseArr,int index){
    
    int i,j;
    
    printf("\t\t\tRegistration Table\n");
    printf("Registration Index\tStudent ID\tCourse ID\tRegistration Status\n");
    for(i = 0; i < index;i++){
        for(j = 0; j < 1; j++){
            if(registerTab[i][2] == 1){
                printf("\t%d\t\t%s\t\t%s\t\t\tR",i,studentArr[registerTab[i][j]],courseArr[registerTab[i][j+1]]);
            }else{
                printf("\t%d\t\t%s\t\t%s\t\t\tD",i,studentArr[registerTab[i][j]],courseArr[registerTab[i][j+1]]);
            }
            
        }
        printf("\n");

    }
}