#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>DP(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        DP[0][i] = matrix[0][i];
    }

    for(int i=1;i<n;i++){
        DP[i][0] = matrix[i][0]+min(DP[i-1][0],DP[i-1][1]);
        for(int j=1;j<n-1;j++){
            int up = matrix[i][j]+DP[i-1][j];
            int upL = matrix[i][j]+DP[i-1][j-1];
            int upR = matrix[i][j]+DP[i-1][j+1];

            DP[i][j] = min({up,upL,upR});
        }
        DP[i][n-1] = matrix[i][n-1] + min(DP[i-1][n-1],DP[i-1][n-2]);
    }

    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        mn = min(mn,DP[n-1][i]);
    }
    return mn;
}