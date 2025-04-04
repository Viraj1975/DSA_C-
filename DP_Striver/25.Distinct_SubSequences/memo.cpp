#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int f(int i,int j,vector<vector<int>>&DP,string &s,string &t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(DP[i][j]!=-1) return DP[i][j];

        if(s[i]==t[j]){
            return DP[i][j]=f(i-1,j-1,DP,s,t)+f(i-1,j,DP,s,t);
        }
        else return DP[i][j]=f(i-1,j,DP,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>DP(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,DP,s,t);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    return 0;
}