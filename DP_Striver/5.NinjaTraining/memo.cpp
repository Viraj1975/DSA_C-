#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &points,vector<vector<int>> &DP,int i,int j){
    if(i==0){
        int maxpt = 0;
        for(int k=0;k<3;k++) {
            if(k!=j){
                maxpt = max(maxpt,points[0][k]);
            }
        }
        return maxpt;
    }
    if(DP[i][j]!=-1) return DP[i][j];

    int pt = 0;
    for(int k=0;k<3;k++){
        if(k != j){
            int merit = points[i][k] + f(points, DP, i - 1, k);
            pt = max(pt,merit);
        }
    }
    return DP[i][j]=pt;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>>DP(n,vector<int>(4,-1));
    return f(points,DP,n-1,3);
}

int main(){
    return 0;
}

