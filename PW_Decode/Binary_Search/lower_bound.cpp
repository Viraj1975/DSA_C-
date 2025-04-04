#include<iostream>
using namespace std;

int lower_bound(int arr[],int n,int k){
    // linear search

    // for(int i=0;i<n;i++){
    //     if(arr[i]>k){
    //         if(i==0) return -1;
    //         return arr[i-1];
    //     }
    // }
    // return -1;


    // Binary Search
    int low = 0;
    int high = n-1;
    while(high>=low){
        int mid = low + (high-low)/2;
        if(arr[mid]==k){
            return arr[mid-1];
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return arr[high];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<lower_bound(arr,n,k);
    return 0;
}