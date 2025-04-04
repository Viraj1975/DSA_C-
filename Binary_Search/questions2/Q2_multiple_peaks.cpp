#include<iostream>
using namespace std;

int multiple_peak(int array[],int size){
    int start=0;int end=size-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid==size-1){
            if(array[mid]>array[mid-1]) return mid;
            else return mid-1;
        }
        else if(mid==0){
            if(array[mid]>array[mid+1]) return mid;
            else return mid+1; 
        }
        else{ 
            if(array[mid]>array[mid+1] && array[mid]>array[mid-1]) return mid;
            else if(array[mid]>array[mid-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    cout<<multiple_peak(array,N);
    return 0;
}