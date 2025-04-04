#include<bits/stdc++.h> 
using namespace std;

int f(int ind,int W,vector<int>&weight,vector<int>&value,vector<vector<int>>&DP){
	if(ind==0){
		if(W>=weight[0]) return value[ind];
		else return 0;
	}

	if(DP[ind][W]!=-1) return DP[ind][W];

	int notTake = f(ind-1,W,weight,value,DP);
	int Take = INT_MIN;
	if(W>=weight[ind]) Take = value[ind]+f(ind-1,W-weight[ind],weight,value,DP);
	return DP[ind][W] = max(Take,notTake);
}

int knapsack(vector<int>&weight, vector<int>&value, int n, int maxWeight){
	vector<vector<int>>DP(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,DP);
}

int main(){
    return 0;
}