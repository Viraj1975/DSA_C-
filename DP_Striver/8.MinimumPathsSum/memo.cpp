#include<bits/stdc++.h> 
using namespace std;

int f(vector<vector<int>>&DP,vector<vector<int>>&grid,int i,int j){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0) return INT_MAX;
    if(DP[i][j]!=-1) return DP[i][j];
    return DP[i][j] = grid[i][j]+min(f(DP,grid,i-1,j),f(DP,grid,i,j-1));
}

int minSumPath(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>DP(n,vector<int>(m,-1));
    return f(DP,grid,n-1,m-1);
}

int main(){
    return 0;
}