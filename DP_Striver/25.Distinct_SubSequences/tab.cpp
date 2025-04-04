#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    const int mod = int(1e9+7);
    vector<vector<int>>DP(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++) DP[i][0]=1;
    for(int i=1;i<=m;i++) DP[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                DP[i][j]=(DP[i-1][j-1]+DP[i-1][j])%mod;
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    cout<<DP[n][m];
    return 0;
}