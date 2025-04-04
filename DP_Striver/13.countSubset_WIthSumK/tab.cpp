#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    vector<vector<int>>DP(n,vector<int>(k+1,-1));

    for(int i=0;i<n;i++) DP[i][0]=1;
    if(arr[0]<=k) DP[0][arr[0]]=1;
    for(int idx=1;idx<n;idx++){
        for(int target=0;target<=k;target++){
            int notTake = DP[idx-1][target];
            int take = 0;
            if(arr[idx]<=target) take=DP[idx-1][target-arr[idx]];
            DP[idx][target] = take + notTake;
        }
    }
    return DP[n-1][k];
}