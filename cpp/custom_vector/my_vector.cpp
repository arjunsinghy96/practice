#include<iostream>
#include<stdlib.h>

using namespace std;

class Vector{
    private:
        int * arr;
        int v_size, v_capacity;

        void _extend_vector(){
            this->v_capacity *=2;
            this-> arr = (int *)realloc(this->arr, this->v_capacity*sizeof(int));
        }

        void _shrink_vector(){
            this->v_capacity /=2;
            this->arr = (int *)realloc(this->arr, this->v_capacity*sizeof(int));
        }

    public:
        Vector(){
            this->arr = new int[16];
            this->v_size = 0;
            this->v_capacity = 16;
        }

        int size(){
            return v_size;
        }

        int capacity(){
            return v_capacity;
        }

        void print(){
            if(this->v_size == 0){
                cout<< "[]" << endl;
                return;
            }
            cout << "[";
            for(int i =0; i<this->v_size-1; i++){
                cout << *(this->arr + i) << ", ";
            }
            cout << *(this->arr + this->v_size)<< "]"<<endl;
        }
};
