#include<bits/stdc++.h>
using namespace std;

int first_Occurrence(vector<int>v,int target){
    int start = 0;
    int end = v.size()-1;
    int idx = INT16_MAX;
    while(end>=start){
        int mid = start+(end-start)/2;
        if(v[mid]==target){
            if(mid>0 && v[mid-1]!=target) return mid;
            if(mid==0) return mid;
            idx = min(idx,mid);
            end = mid -1;
        }
        else if(v[mid]<target){
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return (idx==INT16_MAX)?-1:idx;
}

int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int target;
    cin>>target;
    cout<<first_Occurrence(v,target);
    return 0;
}