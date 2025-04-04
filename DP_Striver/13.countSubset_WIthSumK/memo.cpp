#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>&DP,vector<int>&arr,int i,int k,int n){
	if(k==0) return 1;
	if(i==n-1){
        if(arr[i]==k) return 1;
        else return 0;
    }
	if(DP[i][k]!=-1) return DP[i][k];

	int Take = 0;
	if(arr[i]<=k) Take = f(DP,arr,i+1,k-arr[i],n);
	int notTake = f(DP,arr,i+1,k,n);
	return DP[i][k] = Take+notTake;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>>DP(n,vector<int>(k+1,-1));
	return f(DP,arr,0,k,n);
}

int main(){
    return 0;
}