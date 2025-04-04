#include <bits/stdc++.h> 
using namespace std;

int f(vector<int>&coins,vector<vector<int>>&DP,int i,int p){
    if(i==0){
        if(p%coins[0]==0) return p/coins[0];
        return INT_MAX;
    }
    if(DP[i][p]!=-1) return DP[i][p];
    int notTake = f(coins,DP,i-1,p);
    int Take = INT_MAX;
    if(p>=coins[i]) Take = 1+f(coins,DP,i,p-coins[i]);
    return DP[i][p]=min(Take,notTake);
}

int minimumCoins(int p){
    vector<int>coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    vector<vector<int>>DP(n,vector<int>(p+1,-1));
    return f(coins,DP,n-1,p);
}

int main(){
    return 0;
}