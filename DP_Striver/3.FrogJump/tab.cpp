#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin>>m;
    vector<int>heights(m);
    for(int i=0;i<m;i++){
        cin>>heights[i];
    }
    vector<int>DP(m,-1);
    
    DP[0] = 0;
    DP[1] = abs(heights[0]-heights[1]);

    for(int i=2;i<m;i++){
        int oneStep = DP[i-1] + abs(heights[i]-heights[i-1]);
        int twoStep = DP[i-2] + abs(heights[i]-heights[i-2]);

        DP[i] = min(oneStep,twoStep);
    }
    cout<<DP[m-1]<<endl;
    return 0;
}