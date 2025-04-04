#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(vector<ll>v,vector<vector<ll>>&DP,int i,int j){
    if(i==j) return v[i];
    if(DP[i][j]!=-1) return DP[i][j];
    return DP[i][j] = max(v[i]-f(v,DP,i+1,j),v[j]-f(v,DP,i,j-1));
}

int main(){
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<ll>>DP(3005,vector<ll>(3005,-1));
    cout<<f(v,DP,0,n-1);
    return 0;
}