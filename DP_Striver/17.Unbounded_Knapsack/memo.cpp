#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&weight,vector<int>&value,vector<vector<int>>&DP,int i,int W){
    if(i==0){
        return (W/weight[0])*value[0];
    }
    if(DP[i][W]!=-1) return DP[i][W];
    int notTake = f(weight,value,DP,i-1,W);
    int take = INT_MIN;
    if(W>=weight[i]) take = value[i]+f(weight,value,DP,i,W-weight[i]);

    return DP[i][W] = max(take,notTake);
}

int main(){
    int n;
    cin>>n;
    vector<int>weight(n);
    vector<int>value(n);
    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=0;i<n;i++) cin>>value[i];

    int maxWeight;
    cin>>maxWeight;
    vector<vector<int>>DP(n,vector<int>(maxWeight+1,-1));
    int ans = f(weight,value,DP,n-1,maxWeight);
    return 0;
}