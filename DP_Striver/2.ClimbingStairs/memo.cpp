#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>DP){
    if(n==0) return;1;
    if(n<0) return 0;
    if(DP[n]!=-1) return DP[n];

    return DP[n] = DP[n-1]+DP[n-2]; 
}

int main(){
    int n;
    cin>>n;
    vector<int>DP(n+1,-1);
    int result = f(n,DP);
    cout<<result;
    return 0;
}