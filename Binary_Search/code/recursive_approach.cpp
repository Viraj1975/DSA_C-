#include<iostream>
#include<vector>
using namespace std;

int Binary_Search(vector<int>&v,int start,int end,int k){
    if(start>end) return -1;
    int mid = start + (end-start)/2;
    // this eliminates chances of overflow
    if(v[mid]==k) return mid;
    else if(v[mid]>k) return Binary_Search(v,start,mid-1,k);
    else return Binary_Search(v,mid+1,end,k);
}

int main(){
    int N;int k;
    cin>>N;
    vector<int>v(N);
    int start=0;int end=v.size()-1;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    cin>>k;
    cout<<Binary_Search(v,start,end,k);
    return 0;
}