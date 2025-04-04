#include<iostream>
using namespace std;

int main(){
    int *ptr=NULL;
    {
    int x=10;
    int *ptr=&x;
    }
    // Dangling Pointers

    // it is a type of pointer that points to memory location that is no longer valid.
    return 0;
}