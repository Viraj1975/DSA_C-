#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>weight(n);
    vector<int>value(n);

    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=0;i<n;i++) cin>>value[i];

    int maxWeight;
    cin>>maxWeight;

    vector<vector<int>>DP(n,vector<int>(maxWeight+1,-1));

    for(int wt=0;wt<=maxWeight;wt++){
        DP[0][wt]=(maxWeight/weight[0])*value[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int wt=0;wt<=maxWeight;wt++){
            int notTake = DP[idx-1][wt];
            int Take = INT_MIN;
            if(wt>=weight[idx]) Take = value[idx]+DP[idx][wt-weight[idx]];
            DP[idx][wt]=max(Take,notTake);
        }
    }
    return DP[n-1][maxWeight];
}