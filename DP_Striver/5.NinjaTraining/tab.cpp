#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>DP(n,vector<int>(4,-1));
    vector<vector<int>>points(n,vector<int>(3));
    for(int k=0;k<n;k++) {
        for(int p=0;p<3;p++){
            cin>>points[k][p];
        }
    }
    DP[0][0] = max(points[0][1],points[0][2]);
    DP[0][1] = max(points[0][0],points[0][2]);
    DP[0][2] = max(points[0][0],points[0][1]);
    int mx = INT_MIN;
    for(int i=0;i<3;i++){
        mx = max(mx,points[0][i]);
    }
    DP[0][3] = mx;


    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            DP[i][j] = 0;
            for(int k=0;k<3;k++){
                if(k!=j){
                    int point = points[i][k]+DP[i-1][k];
                    DP[i][j] = max(DP[i][j],point);
                }
            }
        }
    }
    return DP[n-1][3];
}

