#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>obstacles(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>obstacles[i][j];
        }
    }
    if(obstacles[0][0]==-1 || obstacles[n-1][m-1]==-1) return 0;

    vector<vector<int>>DP(n,vector<int>(m,0));
    DP[0][0]=1;
    for(int i=1;i<m;i++){
        if(DP[0][i-1]==1 && obstacles[0][i]==0){
            DP[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(DP[i-1][0]==1 && obstacles[i][0]==0){
            DP[i][0]=1;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(obstacles[i][j]!=-1){
                DP[i][j]=DP[i-1][j]+DP[i][j-1];
            }
        }
    }
    cout<<DP[m-1][n-1];
    return 0;
}