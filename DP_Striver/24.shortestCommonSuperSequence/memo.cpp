// derive the longest common subsequence

// shortest common supersequence length = m+n-lcs;

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>DP(n+1,vector<int>(m+1,0));

        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(str1[idx1-1]==str2[idx2-1]){
                    DP[idx1][idx2] = 1+DP[idx1-1][idx2-1];
                }
                else{
                    DP[idx1][idx2] = max(DP[idx1-1][idx2],DP[idx1][idx2-1]);
                }
            }
        }
        int len = DP[n][m];
        string s = "";
        int i=n;int j=m;
        int idx = len-1;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s+=str1[i-1];
                idx--;
                i--;j--;
            }
            else if(DP[i-1][j]>DP[i][j-1]){
                s+=str1[i-1];
                i--;
            }
            else{
                s+=str2[j-1];
            }
        }

        while(i>0){
            s+=s[i-1];
            i--;
        }
        while(j>0){
            s+=s[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

int main(){
    return 0;
}