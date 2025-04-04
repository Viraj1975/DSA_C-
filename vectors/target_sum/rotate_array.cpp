#include<iostream>
using namespace std;

int main(){
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    int k;int j=0;
    cout<<"Enter the value of k : ";
    cin>>k;
    int ansarray[5];
    k=k%size;
    for(int i=size-k;i<size;i++){
        ansarray[j++]=array[i];
    }
    for(int i=0;i<size-k;i++){
        ansarray[j++]=array[i];
    }
    for(int i=0 ; i<5 ; i++){
        cout<<ansarray[i]<<" ";
    }
    return 0;
}
// 1 2 3 4 5 - 0
// 5 1 2 3 4 - 1
// 4 5 1 2 3 - 2
// 3 4 5 1 2 - 3
// 2 3 4 5 1 - 4
// 1 2 3 4 5 - 5
// 5 1 2 3 4 - 6
// if n>k then n rotations = n-k rotations.


// we can also use reverse operation in vector.

// 1 2 3 4 5
// 5 4 3 2 1
// 5 4 -> 4 5
// 3 2 1 -> 1 2 3 

// 4 5 1 2 3