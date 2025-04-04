#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>&DP,vector<int>&cost,int i,int n){
    if(i==0){
        return n*cost[0];
    }
    if(DP[i][n]!=-1) return DP[i][n];

    int notTake = f(DP,cost,i-1,n);
    int Take = -1e6;
    if(n>=i+1) Take = cost[i] + f(DP,cost,i,n-i-1);
    return DP[i][n] = max(Take,notTake);
}

int minCost(vector<int>&cost,int n){
    vector<vector<int>>DP(n,vector<int>(n+1,-1));
    return f(DP,cost,n-1,n);
}

int main(){
    int n;
    cin>>n;
    vector<int>cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<minCost(cost,n);
    return 0;
}