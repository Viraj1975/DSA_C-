#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>DP(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<=m;i++){
        DP[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        DP[i][0] = 0;
    }

    int mx = 0;
    for(int idx1=1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){
            if(str1[idx1-1]==str2[idx2-1]){
                DP[idx1][idx2] = 1+DP[idx1-1][idx2-1];
                mx = max(mx,DP[idx1][idx2]);
            }
            else{
                DP[idx1][idx2] = 0;
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
// can be space optimized