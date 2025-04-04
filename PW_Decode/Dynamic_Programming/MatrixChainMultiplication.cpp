#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int>&arr,vector<vector<int>>&DP){
    if(i==j || i+1==j) return 0;
    if(DP[i][j]!=-1) return DP[i][j];
    int ans = INT_MAX;
    for(int k=i+1;k<j;k++){
        ans = min(ans,f(i,k,arr,DP)+f(k,j,arr,DP)+arr[i]*arr[k]*arr[j]);
    }
    return DP[i][j]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<vector<int>>DP(1005,vector<int>(1000,0));
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j = len+i-1;
            DP[i][j]=INT_MAX;
            for(int k = i+1;k<j;k++){
                DP[i][j]=min(DP[i][j],DP[i][k]+DP[k][j]+arr[i]*arr[k]*arr[j]);
            }
        }
    }

    // cout<<f(0,n-1,arr,DP);
    return 0;
}