#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &DP,vector<vector<int>> &vec,int i,int j){
    if(j<0 || j>vec[0].size()-1) return 1e5;
    if(i==0) return vec[i][j];
    if(DP[i][j]!=-1) return DP[i][j];

    int up = vec[i][j]+f(DP,vec,i-1,j);
    int upL = vec[i][j]+f(DP,vec,i-1,j-1);
    int upR = vec[i][j]+f(DP,vec,i-1,j+1);

    return DP[i][j]=min({up,upL,upR});
}

int minFallingPathSum(vector<vector<int>> &vec, int n) {
    vector<vector<int>>DP(n,vector<int>(n,-1));
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        int res = f(DP,vec,n-1,i);
        mn = min(mn,res);
    }
    return mn;
}

int main(){
    return 0;
}