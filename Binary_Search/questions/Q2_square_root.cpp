#include<iostream>
#include<vector>
using namespace std;

// Time = O(logx);
// space = O(1);

int square_root(vector<int>&v,int x){
    int end=x-1;
    int start=1;
    int ans=-1;
    while(end>=start){
        int mid=start+(end-start)/2;
        if(v[mid]*v[mid]<=x){
            ans=v[mid];
            start=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}

int main(){
    int x;
    cin>>x;
    vector<int>v;
    for(int i=1;i<=x;i++){
        v.push_back(i);
    }
    cout<<square_root(v,x);
    return 0;
}