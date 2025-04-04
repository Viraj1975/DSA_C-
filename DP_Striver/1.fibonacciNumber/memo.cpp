#include<bits/stdc++.h>
using namespace std;

int f(int n,int a[]){
    if(n<=1) return n;
    if(a[n]!=-1) return a[n];
    return a[n] = f(n-1,a)+f(n-2,a);
}

int main(){
    int n;
    cin>>n;
    int DP[n+1];
    memset(DP,-1,sizeof DP);
    cout<<f(n,DP);
    return 0;
}