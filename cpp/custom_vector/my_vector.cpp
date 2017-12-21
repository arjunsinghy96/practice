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
            if(v_size == 0){
                cout<< "[]" << endl;
                return;
            }
            cout << "[";
            for(int i =0; i<v_size-1; i++){
                cout << *(arr + i) << ", ";
            }
            cout << *(arr + v_size-1)<< "]"<<endl;
        }

        bool is_empty(){
            return v_size == 0;
        }

        int at(int index){
            if(index < v_size){
                return *(arr + index);
            }
            cout << "IndexOutOfBounds\n" << endl;
            exit(-1);
        }

        void push(int value){
            if(v_size == v_capacity){
                _extend_vector();
            }
            *(arr + v_size) = value;
            v_size += 1;
        }

        void insert(int index, int value){
            int temp, temp2=value , i;
            if(v_size == v_capacity){
                _extend_vector();
            }
            if(index < v_size){
                for(i=index; i<v_size; i++){
                    temp = *(arr + i);
                    *(arr + i) = temp2;
                    temp2 = temp;
                }
                *(arr + v_size) = temp2;
                v_size +=1;
            }
        }

        int pop(){
            if(v_size == 0){
                cout << "ArrayEmptyError\n";
                exit(-1);
            }
            v_size -=1;
            int ret_val = *(arr + v_size);
            if(v_size < v_capacity/4){
                _shrink_vector();
            }
            return ret_val;
        }

        void del(int index){
            if(v_size > index){
                for(int i=index; i< v_size -1; i++) {
                    *(arr + i) = *(arr + i + 1);
                }
                v_size -= 1;
            }
            else {
                cout << "IndexOutOfBounds\n";
                exit(-1);
            }
        }

        int find(int value){
            for(int i=0; i< v_size; i++) {
                if(*(arr + i) == value) {
                    return i;
                }
            }
            return -1;
        }

        int& operator[] (int index) {
            if(index > v_size) {
                cout << "IndexOutOfBounds\n";
                exit(-1);
            }
            return arr[index];
        }
};
