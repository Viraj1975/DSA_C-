#include <bits/stdc++.h> 
using namespace std;

int f(vector<int>&coins,vector<vector<int>>&DP,int i,int p){
    if(p==0) return 0;
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

int main(){
    int P;
    cin>>P;
    vector<int>coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    vector<int>DP(P+1,INT_MAX),temp(P+1,INT_MAX);

    for(int i=0;i<=P;i++){
        if(i%coins[0]==0){
            DP[i] = i/coins[0];
        }
    }

    for(int idx=1;idx<n;idx++){
        for(int p=0;p<=P;p++){
            int notTake = DP[p];
            int Take = INT_MAX;
            if(p>=coins[idx] && DP[p-coins[idx]]!=INT_MAX) Take = 1 + DP[p-coins[idx]];
            temp[p]=min(Take,notTake);
        }
        DP=temp;
    }
    cout<<DP[n-1]<<endl;
    return 0;
}