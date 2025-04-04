#include <bits/stdc++.h> 
using namespace std;

int main(){
    int P;
    cin>>P;
    vector<int>coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    vector<vector<int>>DP(n,vector<int>(P+1,INT_MAX));

    for(int i=0;i<=P;i++){
        if(i%coins[0]==0){
            DP[0][i] = i/coins[0];
        }
    }

    for(int idx=1;idx<n;idx++){
        for(int p=0;p<=P;p++){
            int notTake = DP[idx-1][p];
            int Take = INT_MAX;
            if(p>=coins[idx] && DP[idx-1][p-coins[idx]]!=INT_MAX) Take = 1 + DP[idx-1][p-coins[idx]];
            DP[idx][p]=min(Take,notTake);
        }
    }
    cout<<DP[n-1][P]<<endl;
    return 0;
}