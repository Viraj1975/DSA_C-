#include<bits/stdc++.h>
using namespace std;

int LCS(vector<vector<int>>&DP,int idx1,int idx2,string str1,string str2){
    if(idx1<0 || idx2<0) return 0;
    if(DP[idx1][idx2]!=-1) return DP[idx1][idx2];

    if(str1[idx1]==str2[idx2]){
        return DP[idx1][idx2] = 1+LCS(DP,idx1-1,idx2-1,str1,str2);
    } 
    return DP[idx1][idx2] = max(LCS(DP,idx1-1,idx2,str1,str2),LCS(DP,idx1,idx2-1,str1,str2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>DP(n,vector<int>(m,-1));
    cout<<LCS(DP,n-1,m-1,str1,str2);
    return 0;
}