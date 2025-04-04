#include<bits/stdc++.h>
using namespace std;

int f(int n,int k,vector<int>&heights,vector<int>&DP){
    if(n==0) return 0;
    if(n==1) return abs(heights[0]-heights[1]);

    if(DP[n]!=-1) return DP[n];

    int mn = INT_MAX;
    for(int i=1;i<=min(k,n);i++){
        mn = min(f(n-i,k,heights,DP)+abs(heights[n]-heights[n-i]),mn);    
    }
    return DP[n]=mn;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    vector<int>DP(n,-1);
    int result = f(n-1,k,heights,DP);
    cout<<result<<endl;
    return 0;
}