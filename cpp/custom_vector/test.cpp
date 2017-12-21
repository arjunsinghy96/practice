#include<iostream>
#include<assert.h>
#include"my_vector.cpp"

using namespace std;

int main(){
    Vector v;
    assert(v.size() == 0);
    assert(v.capacity() == 16);
    for(int i=0;i<20; i++){
        v.push(2*i);
    }
    assert(v.size() == 20);
    assert(v.capacity() == 32);
    v.print();
    v.del(10);
    assert(v.size() == 19);
    v.insert(5, 100);
    v.print();
    for(int i=0; i<17; i++){
        v.pop();
    }
    v.print();
    assert(v.capacity() == 8);
    return 0;
}
