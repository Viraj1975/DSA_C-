#include<iostream>
#include<queue>
using namespace std;

int kth_largest(int arr[],int k,int size){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<size;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int size;
    cout<<"Enter the size of Array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of Array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    int ans = kth_largest(arr,k,size);
    cout<<"The Required number is : "<<ans;
    return 0;
}