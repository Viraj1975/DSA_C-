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
    vector<int>DP(n);

    for(int i=0;i<n;i++){
        DP[i] = matrix[0][i];
    }

    for(int i=1;i<n;i++){
        vector<int>temp(n);
        temp[0] = matrix[i][0]+min(DP[0],DP[1]);
        for(int j=1;j<n-1;j++){
            int up = matrix[i][j]+DP[j];
            int upL = matrix[i][j]+DP[j-1];
            int upR = matrix[i][j]+DP[j+1];

            temp[j] = min({up,upL,upR});
        }
        temp[n-1] = matrix[i][n-1] + min(DP[n-1],DP[n-2]);
        DP = temp;
    }

    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        mn = min(mn,DP[i]);
    }
    return mn;
}