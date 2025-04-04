#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,K,L;
    cin>>t;
    cin>>K;
    cin>>L;
    vector<bool>DP(1000005,-1);
    DP[1]=1;
    DP[K]=1;
    DP[L]=1;

    for(int i=2;i<1000000;i++){
        if(i==L || i==K) continue;

        DP[i] = !(DP[i-1] && ((i-K>=1) ? DP[i-K]:1) && ((i-L>=1) ? DP[i-L]:1));
    }
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(DP[n]==1) cout<<"A";
        else cout<<"B";
    }

    return 0;
}