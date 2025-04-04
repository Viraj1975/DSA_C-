#include<bits/stdc++.h>
using namespace std;
int DP[105][105][2];

int f(int n,int k,int last){
    if(n==0) return 0;
    if(n==1){
        if(k==0) return 1;
        else return 0;
    }

    if(DP[n][k][last]!=-1) return DP[n][k][last];

    if(last==1){
        return DP[n][k][last] = f(n-1,k,0)+f(n-1,k-1,1);
    }
    else{
        return DP[n][k][last] = f(n-1,k,0)+f(n-1,k,1);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(DP,-1,sizeof DP);
        int ans = f(n,k,0)+f(n,k,1);
        cout<<num<<" "<<ans;
    }
    
    return 0;
}