#include<iostream>
#include"my_vector.cpp"

using namespace std;

int main(){
    Vector v;
    cout << v.size() << endl;
    cout << v.capacity()<< endl;
    v.print();
    return 0;
}
