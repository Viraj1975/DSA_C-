#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    vector<vector<int>>DP(n,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++){
        DP[0][i] = (i)*cost[0];
    }

    for(int idx=1;idx<n;idx++){
        for(int len=0;len<=n;len++){
            int notTake = DP[idx-1][len];
            int Take = INT_MIN;
            if(len>=idx+1) Take = cost[idx]+DP[idx][len-idx-1];
            DP[idx][len] = max(Take,notTake);
        }
    }
    cout<<DP[n-1][n];
    return 0;
}