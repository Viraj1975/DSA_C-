#include<iostream>
using namespace std; 

int main(){
    // void pointers

    // these are special pointers that can point to any datatype.
    // these cannot be dereferenced directly.
    // type casting has to be done.

    float f=10.06;
    int x=34;

    void *ptr=&x;
    ptr=&f;

    // dereferencing.
    int *integer_pointer=(int*)ptr;
    cout<<*integer_pointer<<endl;
    return 0;
}
