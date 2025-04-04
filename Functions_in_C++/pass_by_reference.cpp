#include<iostream>
using namespace std;

void change(int &z){
    z=17;
}

int main(){
    int p=18;
    change(p);
    // here z and a are accessing the same memory location
    cout<<p;
    return 0;
}

// default parameter value //
// it is a value in the function declaration automatically assigned by the compiler if the calling function
// does not pass any value to that argument.
// 
// int add(int a=1 ; int b=2 ; int c=3)

// but 
// int add(int a; int b=0 ; int c) -> this will throw an error
