#include<bits/stdc++.h>
using namespace std;

void BuildSegmentTree(vector<int>&SGT,vector<int>&arr,int start,int end,int i){
    int mid = start + (end-start)/2;
    if(start==end){
        SGT[i]=arr[start];
        return;
    }
    BuildSegmentTree(SGT,arr,start,mid,2*i+1);
    BuildSegmentTree(SGT,arr,mid+1,end,2*i+2);
    SGT[i] = max(SGT[2*i+1],SGT[2*i+2]);
}

int getMax(vector<int>&SGT,int i,int low,int high,int &l,int &r){
    if(r<low || l>high){
        return INT_MIN;
    }
    if(low<=l && high>=r){
        return SGT[i];
    }
    int mid = low + (high-low)/2;
    int left = getMax(SGT,2*i+1,low,mid,l,r);
    int right = getMax(SGT,2*i+2,mid+1,high,l,r);
    return max(left,right);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>SGT(4*n);
    BuildSegmentTree(SGT,arr,0,n-1,0);
    int l,r;
    cin>>l>>r;

    cout<<getMax(SGT,0,0,n-1,l,r)<<endl;
    return 0;
}