#include<iostream>
using namespace std;

void generate_subsets(int arr[],int n){
    int x = 1<<n;
    for(int i = 0;i<x;i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    generate_subsets(arr,n);
}