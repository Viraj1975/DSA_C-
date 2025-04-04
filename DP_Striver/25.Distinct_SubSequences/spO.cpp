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
    vector<int>DP(m+1,0),curr(m+1,0);
    DP[0] = 1;curr[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j]=(DP[j-1]+DP[j])%mod;
            }
            else{
                curr[j]=DP[j];
            }
        }
        DP=curr;
    }
    cout<<DP[m];
    return 0;
}