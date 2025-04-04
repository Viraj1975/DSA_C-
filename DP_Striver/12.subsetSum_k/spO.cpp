#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;

    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;

    for(int idx=0;idx<n;idx++){
        for(int target=1;target<=k;target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[idx]<=target) take=prev[target-arr[idx]];
            curr[target] = take || notTake;
        }
        prev=curr;
    }
    return prev[k];
}

// prev : DP
// curr : temp