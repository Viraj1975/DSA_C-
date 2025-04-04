#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009

int f(int i,int j,vector<vector<int>>&mz,vector<vector<int>>&DP){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 || mz[i][j]==-1) return 0;
    if(DP[i][j]!=-1) return DP[i][j];

    return DP[i][j] = (f(i-1,j,mz,DP)+f(i,j-1,mz,DP))%mod; 
}

int mazeObstacles(int n, int m, vector<vector<int>>&mat){
    vector<vector<int>>DP(n,vector<int>(m,-1));
    if(mat[0][0]==-1 || mat[n-1][m-1]==-1) return 0;
    return f(n-1,m-1,mat,DP);
}

int main(){
    return 0;
}