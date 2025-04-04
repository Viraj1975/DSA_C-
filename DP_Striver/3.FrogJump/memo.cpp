#include<bits/stdc++.h>
using namespace std;

int minEnergy(int n,vector<int>&h,vector<int>&DP){
    if(n==0) return 0;
    if(n==1) return abs(h[0]-h[1]);

    if(DP[n]!=-1) return DP[n];

    int oneStep = abs(h[n]-h[n-1]) + minEnergy(n-1,h,DP);
    int twoStep = abs(h[n]-h[n-2]) + minEnergy(n-2,h,DP); 

    return DP[n] = min(oneStep,twoStep);
}

int main(){
    int m;
    cin>>m;
    vector<int>heights(m);
    for(int i=0;i<m;i++){
        cin>>heights[i];
    }
    vector<int>DP(m,-1);
    int result = minEnergy(m-1,heights,DP);
    return 0;
}