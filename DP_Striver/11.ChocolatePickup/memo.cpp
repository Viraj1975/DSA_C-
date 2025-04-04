#include <bits/stdc++.h> 
using namespace std;

int f(vector<vector<vector<int>>>&DP,vector<vector<int>>&grid,int i,int j1,int j2){
    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return -1e5;
    if(i==grid.size()-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(DP[i][j1][j2]!=-1) return DP[i][j1][j2];

    int mx = -1e5;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value = 0;
            if(j1==j2) value = grid[i][j1];
            else value = grid[i][j1]+grid[i][j2];

            mx = max(mx,value+f(DP,grid,i+1,j1+dj1,j2+dj2));
        }
    }
    return DP[i][j1][j2]=mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>DP(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(DP,grid,0,0,c-1);
}

int main(){
    return 0;
}