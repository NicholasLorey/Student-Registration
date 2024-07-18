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
#include "studentsArray.h"
#include "coursesArray.h"
#include "registrationTable.h"
#include "mallocR.h"
#include "displayR.h"
#include "dropTable.h"

/******************************
 * Function name - print_menu
 * Purpose - to print the menu table
 * Student name - Nicholas Lorey
*******************************/
void print_menu(){
    printf("\n");
    printf("Main Menu:\n");
    printf("(1):Register a student into a course.\n");
    printf("(2):Drop a student from a course\n");
    printf("(3):Display Registration table.\n");
    printf("(4):Exit.\n");
    printf("Enter an option from the menu:\n");
}

/******************************
 * Function name - main
 * Purpose - all the program start here
 * Student name - Nicholas Lorey
*******************************/
int main(void){
    int studentCount,courseCount,checkError,userOpt,toContinue;
    int i=0;
    char** studentsArray;
    char** coursesArray;
    int** registerTable;
    toContinue = 1;
    
    printf("Welcome to Student Registration System\n");
    
    do{
        printf("Enter the number of students to register:");
        checkError = scanf("%d",&studentCount);
        while (getchar() != '\n');
        /*if user input is negative or error, it will end the program*/
        if(checkError == 0 || studentCount <=0){
            printf("ERROR: Invalid input\n");}
        /*exit, return, or take some other action*/
    }while(checkError==0 || studentCount <=0);
    studentsArray = students_array(studentCount);
    do{
        printf("Enter the number of courses to avaiable:");
        checkError = scanf("%d",&courseCount);
        while (getchar() != '\n');
        /*if user input is negative or error, it will end the program*/
        if(checkError == 0 || courseCount <=0){
            printf("ERROR: Invalid input\n");}
        /*exit, return, or take some other action*/
    }while(checkError==0 || courseCount <=0);

    coursesArray = courses_array(courseCount);
  
    registerTable = toMalloc(registerTable,studentCount,courseCount);

    do{
        print_menu();
        checkError = scanf("%d",&userOpt);
        while(getchar()!='\n');
        switch(userOpt){
            case 1:
                toRegister(registerTable,studentsArray,coursesArray,studentCount,courseCount,i);
                i++;
                break;
            case 2:
                displayTable(registerTable,studentsArray,coursesArray,i);
                toDrop(registerTable,i);
                displayTable(registerTable,studentsArray,coursesArray,i);
                break;
            case 3:
                displayTable(registerTable,studentsArray,coursesArray,i);
                break;
            case 4:
                printf("Exiting...");
                free(registerTable);
                free(studentsArray);
                free(coursesArray);
                toContinue = 0;
                break;
            default:
                printf("please enter a valid number");
                toContinue =1;
                break;
        }
        
    }while(toContinue==1 || checkError ==0);


return 0;
}