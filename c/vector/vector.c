/* Copyright (c) 2017 arjunsinghy96
 * * A primary implementation of dynamic array/vector
 */

#include<stdio.h>
#include<stdlib.h>
#include"exception.c"

#define INIT_SIZE 16

typedef struct vectors{
    int *arr;
    int size;
    int capacity;
}vector;

int is_empty(vector * v){
    return v->size > 0;
}

void _shrink_vector(vector *v){
    v->capacity /= 2;
    v->arr = realloc(v->arr, v->capacity * sizeof(int));
}

void _extend_vector(vector *v){
    v->arr = realloc(v->arr, 2*v->capacity *sizeof(int));
    v->capacity *= 2;
}

void append(vector *v, int num){
    if(v->arr == NULL){
        printf("You need to initialize the vector first");
        return;
    }
    if(v->size == v->capacity){
        _extend_vector(v);
    }
    *(v->arr + v->size) = num;
    v->size += 1;
}

int pop(vector *v) {
    if(v->size == 0){
        Exception excpt = new_exception(41);
        printf("Error %d: %s\n", excpt.exp_no, excpt.exp_name);
        exit(-1);
    }
    v->size -= 1;
    int ret_val = *(v->arr + v->size);
    if(v->size < v->capacity/4){
        _shrink_vector(v);
    }
    return ret_val;
}

int get(vector *v, int position){
    if(position < v->size){
        return *(v->arr + position);
    }
    else {
        Exception err = new_exception(42);
        printf("Error %d: %s %d\n",err.exp_no, err.exp_name, position);
        exit(-1);
    }
}

void set(vector *v, int position, int num){
    if(position < v->size){
        *(v->arr + position) = num;
    }
    else {
        Exception err = new_exception(1);
        printf("%s %d\n", err.exp_name, position);
        exit(-1);
    }
}

void insert_at(vector *v, int position, int num){
    int temp, temp2=num, i;
    if(v->size == v->capacity){
        _extend_vector(v);
    }
    if(position < v->size){
        for(i=position; i< v->size; i++){
            temp = *(v->arr + i);
            *(v->arr + i) = temp2;
            temp2 = temp;
        }
        *(v->arr + v->size) = temp2;
        v->size += 1;
    }
}

void delete(vector * v, int index) {
    int i;
    if(v->size > index){
        for(i=index; i<v->size - 1;i++) {
            *(v->arr + i) = *(v->arr + i + 1);
        }
        v->size -= 1;
    }
}

int find(vector *v, int value){
    int i;
    for(i=0; i<v->size; i++){
        if(*(v->arr + i) == value){
            return i;
        }
    }
}

void init_vector(vector *v){
    v->arr = malloc(INIT_SIZE* sizeof(int));
    v->size = 0;
    v->capacity = 16;
}
