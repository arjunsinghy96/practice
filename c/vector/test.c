#include<stdio.h>
#include<assert.h>
#include"vector.c"

void print(vector x) {
    int i;
    printf("[");
    for(i=0;i < x.size - 1; i++){
        printf("%d, ", get(&x, i));
    }
    printf("%d]\n", get(&x, x.size-1));
}

void main(){
    int i;
    vector x;
    init_vector(&x);
    append(&x, 10);
    print(x);
    insert_at(&x, 0, 9);
    print(x);
    i = pop(&x);
    assert(i == 10);
    printf("%d\n", i);
    print(x);
}
