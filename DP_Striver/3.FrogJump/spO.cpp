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
    
    int prev2 = 0;
    int prev1 = abs(heights[0]-heights[1]); 

    for(int i=2;i<m;i++){
        int oneStep = prev1 + abs(heights[i]-heights[i-1]);
        int twoStep = prev2 + abs(heights[i]-heights[i-2]);

        int curr = min(oneStep,twoStep);
        prev2 = prev1;
        prev1 = curr; 
    }
    cout<<DP[m-1]<<endl;
    return 0;
}