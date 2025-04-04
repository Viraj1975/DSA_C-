#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>DP(n,vector<int>(m,-1));
    DP[0][0] = grid[0][0];
    for(int i=1;i<m;i++){
        DP[0][i] = grid[0][i]+DP[0][i-1];
    }
    for(int i=1;i<n;i++){
        DP[i][0] = grid[i][0]+DP[i-1][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            DP[i][j] = grid[i][j]+min(DP[i-1][j],DP[i][j-1]);
        }
    }
    return 0;
}