#include<iostream>
using namespace std;

int find_unique(int arr[],int size){
    int unique_number = 0;
    for(int i=0;i<size;i++){
        unique_number = unique_number^arr[i];
    }
    return unique_number;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<find_unique(arr,n);
}