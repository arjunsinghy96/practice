/* Copyright (c) 2017 arjunsinghy96
 *
 * My little exception implementation for the vectors
 */

#include<stdio.h>
#include<string.h>

typedef struct err{
    int exp_no;
    char exp_name[100];
}Exception;

Exception new_exception(int num){
    Exception expt;
    expt.exp_no = num;
    switch(num){
        case 41:
            strcpy(expt.exp_name, "Empty vector");
            break;
        case 42:
            strcpy(expt.exp_name, "Index out of bounds");
            break;
        default:
            strcpy(expt.exp_name, "Unknown error");
        }
    return expt;
}
