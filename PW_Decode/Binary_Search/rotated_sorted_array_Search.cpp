#include<bits/stdc++.h>
using namespace std;

int find_target(vector<int>arr,int x){
    int start = 0;
    int end = arr.size()-1;
    int ans = -1;
    while(end>=start){
        int mid = start + (end-start)/2;
        
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    find_target(v,target);
    return 0;
}