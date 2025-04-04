#include<bits/stdc++.h>
using namespace std;

vector<int>SGT;
vector<int>Lazy;

void BuildSegmentTree(vector<int>&arr,int start,int end,int i){
    int mid = start + (end-start)/2;
    if(start==end){
        SGT[i]=arr[start];
        return;
    }
    BuildSegmentTree(arr,start,mid,2*i+1);
    BuildSegmentTree(arr,mid+1,end,2*i+2);
    SGT[i] = SGT[2*i+1]+SGT[2*i+2];
}

int getSum(int i,int low,int high,int &l,int &r){
    // check for lazy updates
    if(Lazy[i]!=0){
        int rangeSize = high-low+1;
        SGT[i]+=rangeSize*Lazy[i];
        if(low!=high){
            Lazy[2*i+1] += Lazy[i];
            Lazy[2*i+2] += Lazy[i];
        }
        Lazy[i] = 0;
    }

    if(r<low || l>high) return 0;
    if(low<=l && high<=r) return SGT[i];
    int mid = low + (high-low)/2;
    int left = getSum(2*i+1,low,mid,l,r);
    int right = getSum(2*i+2,mid+1,high,l,r);
    return left+right;
}

void UpdateRange(int i,int low,int high,int left,int right,int value){
    if(Lazy[i]!=0){
        int rangeSize = high-low+1;
        SGT[i]+=rangeSize*Lazy[i];
        if(low!=high){
            Lazy[2*i+1] += Lazy[i];
            Lazy[2*i+2] += Lazy[i];
        }
        Lazy[i] = 0;
    }
    if(low>right || high<left) return;
    if(low>=left && right>=high){
        // update entire low to high

        int rangeSize = high-low+1;
        SGT[i]+=value*rangeSize;
        if(low!=high){
            Lazy[2*i+1] += value;
            Lazy[2*i+2] += value;
        }
        return;
    }
    int mid = low + (high-low)/2;
    UpdateRange(2*i+1,low,mid,left,right,value);
    UpdateRange(2*i+2,mid+1,high,left,right,value);
    SGT[i] = SGT[2*i+1] + SGT[2*i+2];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SGT.resize(4*n);
    Lazy.resize(4*n,0);
    BuildSegmentTree(arr,0,n-1,0);
    int l,r;
    cin>>l>>r;
    cout<<getSum(0,0,n-1,l,r)<<endl;

    UpdateRange(0,0,n-1,2,5,10);
    return 0;
}