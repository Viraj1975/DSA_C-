#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    vector<int>DP(m+1,0),curr(m+1,0);
    
    for(int i=0;i<=m;i++){
        DP[i] = 0;
    }

    for(int idx1=1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){
            if(str1[idx1-1]==str2[idx2-1]){
                curr[idx2] = 1+DP[idx2-1];
            }
            else{
                curr[idx2] = max(DP[idx2],curr[idx2-1]);
            }
        }
        DP = curr;
    }
    cout<<DP[m];
    return 0;
}