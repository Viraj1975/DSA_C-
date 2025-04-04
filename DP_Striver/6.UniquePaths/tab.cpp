#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>DP(m,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        DP[0][i] = 1;
    }
    for(int i=1;i<m;i++){
        DP[i][0] = 1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            DP[i][j] = DP[i-1][j]+DP[i][j-1];
        }
    }
    cout<<DP[m-1][n-1];
    return 0;
}