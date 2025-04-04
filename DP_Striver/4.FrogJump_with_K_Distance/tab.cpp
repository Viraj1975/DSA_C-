#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    vector<int>DP(n,INT_MAX);
    DP[0] = 0;
    DP[1] = abs(heights[0]-heights[1]); 
    for(int i=2;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0) DP[i] = min(DP[i-j]+abs(heights[i]-heights[i-j]),DP[i]);    
        }
    }
    cout<<DP[n-1];
    return 0;
}