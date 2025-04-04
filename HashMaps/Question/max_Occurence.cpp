#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int max_occurence(int arr[],int size){
    unordered_map<int,int>m;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
    }
    int largest = 0;
    int ans = arr[0];
    for(auto i:m){
        if(i.second>largest){
            largest = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];
    cout<<"Enter the elements of array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int result = max_occurence(arr,size);
    cout<<result;
    return 0;
}