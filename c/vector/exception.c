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
        case 0:
            strcpy(expt.exp_name, "Empty vector");
            break;
        case 1:
            strcpy(expt.exp_name, "Index out of bounds");
            break;
        default:
            strcpy(expt.exp_name, "Unknown error");
        }
    return expt;
}
