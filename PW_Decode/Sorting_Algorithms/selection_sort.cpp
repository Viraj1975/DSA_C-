#include<bits/stdc++.h>
using namespace std;

void Selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallest = arr[i];
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<smallest){
                smallest = arr[j];
                idx = j;
            }
        }
        if(idx!=i){
            swap(arr[i],arr[idx]);
        }
    }
}

int main(){
    int arr[] = {5,1,3,2,4};
    Selection_sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}