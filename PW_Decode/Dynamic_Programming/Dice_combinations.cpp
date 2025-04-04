#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long Combinations(long long x,vector<long long>&DP){
    if(x==0) return 1;
    if(x<0) return 0;
    if(DP[x]!=-1) return DP[x];

    DP[x]=0;
    for(int i=1;i<=6;i++){
        if(i>x) continue;
        DP[x] = (DP[x]%mod + Combinations(x-i,DP)%mod)%mod;
    }
    
    return DP[x];
}

int main(){
    long long n;
    cin>>n;
    vector<long long>DP(n+1,-1);
    cout<<Combinations(n,DP);
    return 0;
}