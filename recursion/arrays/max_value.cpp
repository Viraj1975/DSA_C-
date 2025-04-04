#include<iostream>
using namespace std;

int traverse(int arr[],int size,int idx){
    if(idx==size-1) return arr[idx];
    return max(arr[idx],traverse(arr,size,idx+1));
}

int main(){
    int arr[]={2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);int idx=0;
    int result = traverse(arr,size,idx);
    cout<<result;
    return 0;
}