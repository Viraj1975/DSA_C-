#include<iostream>
#include<vector>
using namespace std;

int Binary_Search(vector<int>&v,int k){
    int start=0;int end=v.size()-1;
    int index=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        // this eliminates chances of overflow
        if(v[mid]==k){
            index=mid;
            end=mid-1;
        }
        else if(v[mid]<k){
            start=mid+1;
        }
        else end=mid-1;
    }
    return index;
}

int main(){
    int N;int k;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    cin>>k;
    cout<<Binary_Search(v,k);
    return 0;
}