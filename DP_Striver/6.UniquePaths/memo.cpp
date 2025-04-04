#include <bits/stdc++.h> 
using namespace std;

int f(int i,int j,vector<vector<int>>&DP){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(DP[i][j]!=-1) return DP[i][j];
	return DP[i][j] = f(i-1,j,DP)+f(i,j-1,DP);
}

int uniquePaths(int m, int n){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>>DP(m,vector<int>(n,-1));
	return f(m-1,n-1,DP);
}

int main(){
    return 0;
}