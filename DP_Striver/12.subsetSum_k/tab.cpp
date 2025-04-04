#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    vector<vector<bool>>DP(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++) DP[i][0]=true;
    DP[0][arr[0]]=true;
    for(int idx=1;idx<n;idx++){
        for(int target=1;target<=k;target++){
            bool notTake = DP[idx-1][target];
            bool take = false;
            if(arr[idx]<=target) take=DP[idx-1][target-arr[idx]];
            DP[idx][target] = take || notTake;
        }
    }
    return DP[n-1][k];
}