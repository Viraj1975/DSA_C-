#include<iostream>
using namespace std;

int main(){
    int x=10;
    int* ptr;
    // wild pointers 

    // it occurs when we declare a pointer but not initialize it 
    // in this case the pointers points some random memory location
    // due to this we may get some undefined behaviour and crashes or segmentation fault in some cases.

    // cout<<ptr<<"\n";
    return 0;
}