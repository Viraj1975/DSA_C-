#include <bits/stdc++.h>
using namespace std;

// we can start from 0,0 to the last row

int f(vector<vector<int>> &triangle,int i,int j,vector<vector<int>>&DP){
	if(i==triangle.size()-1) return triangle[i][j];
	if(DP[i][j]!=-1) return DP[i][j];

	int down = f(triangle,i+1,j,DP);
	int dg = f(triangle,i+1,j+1,DP);

	return DP[i][j] = triangle[i][j]+min(down,dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>DP;
	for(int i=0;i<n;i++){
		vector<int>temp(i+1,-1);
		DP.push_back(temp);
	}
    return f(triangle,0,0,DP);
}

int main(){
    return 0;
}