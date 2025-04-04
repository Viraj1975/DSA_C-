#include<iostream>
using namespace std;

void traverse(int arr[],int size,int idx){
    if(idx==size) return;
    cout<<arr[idx]<<" ";
    return traverse(arr,size,idx+1);
}

int main(){
    int arr[]={2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);int idx=0;
    traverse(arr,size,idx);
    return 0;
}