#include <bits/stdc++.h>
using namespace std; 

int f(vector<int>&arr,vector<vector<int>>&DP,int i,int k){
    if(k==0) return 1;
    if(i==arr.size() || k<0){
        return 0;
    }
    if(DP[i][k]!=-1) return DP[i][k];

    int Take = f(arr,DP,i+1,k-arr[i]);
    int notTake = f(arr,DP,i+1,k);

    return DP[i][k]=Take || notTake;
}

bool subsetSumToK(int n,int k,vector<int>&arr){
    vector<vector<int>>DP(n,vector<int>(k+1,-1));
    return f(arr,DP,0,k)!=0;
}

int main(){
    
    return 0;
}