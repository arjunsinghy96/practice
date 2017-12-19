#include<stdio.h>
#include<assert.h>
#include"vector.c"

void main(){
    vector x;
    init_vector(&x);
    append(&x, 10);
    int i = x.pop();
    assert(i == 10);
    printf("%d\n", i);
}
