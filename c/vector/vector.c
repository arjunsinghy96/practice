/* Copyright (c) 2017 arjunsinghy96
 *
 * A primary implementation of dynamic array/vector
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"exception.c"

#define INIT_SIZE 16

typedef struct vectors{
    int *arr;
    int size;
    int capacity;
    int (*pop)();
    bool empty;
}vector;

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
    v->empty = 0;
}

int _pop(vector *v) {
    if(v->size == 0){
        return NULL;
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
        Exception err = new_exception(1);
        printf("%s\n",err.exp_name);
        exit(-1);
    }
}

void init_vector(vector *v){
    v->arr = malloc(INIT_SIZE* sizeof(int));
    v->size = 0;
    v->capacity = 16;
    v->empty = 1;
    v->pop = _pop;
}
