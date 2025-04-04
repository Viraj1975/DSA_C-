#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<vector<int>>DP(n,vector<int>(3,0));
    
    int a,b,c;
    cin>>a>>b>>c;
    DP[0][0]=a;
    DP[0][1]=b;
    DP[0][2]=c;

    for(int i=1;i<n;i++){
        DP[i][0] = a + max(DP[i-1][1],DP[i-1][2]);

        DP[i][1] = b + max(DP[i-1][0],DP[i-1][2]);

        DP[i][2] = c + max(DP[i-1][0],DP[i-1][2]);
    }
    cout<<max({DP[n-1][0],DP[n-1][1],DP[n-1][2]});
    return 0;
}