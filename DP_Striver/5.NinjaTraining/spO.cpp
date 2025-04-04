#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>DP(4,0);
    vector<vector<int>>points(n,vector<int>(3));
    for(int k=0;k<n;k++) {
        for(int p=0;p<3;p++){
            cin>>points[k][p];
        }
    }
    DP[0] = max(points[0][1],points[0][2]);
    DP[1] = max(points[0][0],points[0][2]);
    DP[2] = max(points[0][0],points[0][1]);
    int mx = INT_MIN;
    for(int i=0;i<3;i++){
        mx = max(mx,points[0][i]);
    }
    DP[3] = mx;

    for(int i=1;i<n;i++){
        vector<int>temp(4,0);
        for(int j=0;j<4;j++){
            temp[j] = 0;
            for(int k=0;k<3;k++){
                if(k!=j){
                    temp[j] = max(temp[j],points[i][j]+DP[j]);
                }
            }
        }
        DP = temp;
    }
    return DP[3];
}

