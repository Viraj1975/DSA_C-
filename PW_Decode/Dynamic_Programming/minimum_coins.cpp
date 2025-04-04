#include<bits/stdc++.h>
using namespace std;

int minimum_coins(vector<int>&v,int x,vector<int>&DP){
    if(x==0) return 0;
    if(DP[x]!=-1) return DP[x];
    int result = INT_MAX;
    for(int j=0;j<v.size();j++){
        if(x-v[j]<0) continue;
        result=min(result,minimum_coins(v,x-v[j],DP));
    }
    if(result==INT_MAX) return DP[x]=INT_MAX;
    return DP[x]=1+result;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int k;
    cin>>k;
    vector<int>DP(k+1,-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans = minimum_coins(v,k,DP);
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}