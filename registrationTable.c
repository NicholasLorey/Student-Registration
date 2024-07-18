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
#include "registrationTable.h"
#include <stdio.h>

/******************************
 * Function name - toRegister
 * Purpose - to register the student to the register table
 * Function In parameters - take the register table, course table, and student table, course size and student size
 * Function Out parameters - it will add/modified the index of the course & student to the register table
 * Student name - Nicholas Lorey
*******************************/
void toRegister(int** registerTab,char** studentArr, char** courseArr, int studentSize, int courseSize, int index){

    int i,checkCourse,checkStudent,courseFound,studentFound,check;
    char studentToRegister[5]; 
    char courseToRegister[7];
    int rowSize = studentSize*courseSize;
    
    printf("List of Student Ids\n");
    for(i = 0;i < studentSize; i++){
        printf("Index[%d]\t%s\n",i, studentArr[i]);
    }
    do{
        printf("Enter the Student's Id to register a course:");
        scanf("%s", studentToRegister);

        studentFound = findIndex(studentArr,studentSize,studentToRegister);

        if(studentFound == -1){
            printf("student ID not found\n");
        }
    }while(studentFound == -1);
    
    printf("List of Available Course Id\n");
    for(i = 0;i < courseSize; i++){
        printf("Index[%d]\t%s\n",i, courseArr[i]);
    }

    do{
        printf("Enter the Course Id [3-Alphas][4-digits]:");
        scanf("%s", courseToRegister);

        courseFound = findIndex(courseArr,courseSize,courseToRegister);

        for(i = 0; i <= index;i++){
            checkStudent = registerTab[i][0];
            checkCourse = registerTab[i][1];
            check = 1;

            if(registerTab[i][2] == 0 && index > 0 && studentFound == checkStudent && courseFound == checkCourse){
                check = -2;
                break;
            }else if(studentFound == checkStudent && courseFound == checkCourse && index > 0){
                check = -1;
                break;
            }
        }
        if(courseFound == -1){
            printf("Course ID not found\n");
        }else if(check == -1){
            printf("Already on record.\n");
            printf("Student id %s cannot register to course %s.\n", studentToRegister,courseToRegister);
            printf("Register unsuccessful\n");
        }else if(check == -2){
            printf("Student id %s have dropped out from course %s.\n", studentToRegister,courseToRegister);
            printf("Student id %s cannot register to course %s.\n", studentToRegister,courseToRegister);
            printf("Register unsuccessful\n");
        }
    }while(courseFound == -1 || check == -1 || check ==-2);
    

    
    for(i = index; i < rowSize;i++){
        
        registerTab[i][0] = studentFound;
        registerTab[i][1] = courseFound;
        registerTab[i][2] = 1;
        
    }
    printf("Registration Successful\n");


}

