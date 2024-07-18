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

#include "dropTable.h"
#include <stdio.h>

/******************************
 * Function name - toDrop
 * Purpose - to drop the course that the user want student to drop
 * Function In parameters - take the register table to be modified
 * Function Out parameters - it change the index of register (0) to drop(1)
 * Student name - Nicholas Lorey
*******************************/
void toDrop(int **registerTab,int index){
    int i, indexDrop, toContinue,checkError;

    do{
        printf("Please select Index number to drop student registration: ");
        checkError = scanf("%d", &indexDrop);
        while (getchar() != '\n');
        toContinue = 1;
        for(i = 0; i < index;i++){
            if(i == indexDrop){
                registerTab[i][2] = 0;
                printf("Drop course successful.\n");
                toContinue = 0;
                break;
            }
            
            
        }
        if(toContinue == 1 || checkError == 0){
            printf("Index number not found\n");
        }
    }while(toContinue == 1 || checkError == 0) ;
    

}