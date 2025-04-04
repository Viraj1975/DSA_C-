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

    vector<int>DP(n,1);
    DP[0] = grid[0][0];
    for(int i=1;i<m;i++){
        DP[i] = DP[i-1]+grid[0][i];
    }

    for(int i=1;i<n;i++){
        vector<int>temp;
        temp.push_back(grid[i][0]+DP[0]);
        for(int j=1;j<m;j++){
            int curr = grid[i][j]+min(temp[i-1],DP[i-1]);
            DP[i] = curr;
            temp.push_back(curr);
        }
        DP=temp;
    }
    return 0;
}