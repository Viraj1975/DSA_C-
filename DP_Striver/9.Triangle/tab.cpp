#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>triangle;
    for(int i=0;i<n;i++){
        vector<int>temp(i+1);
        for(int j=0;j<n;j++){
            cin>>temp[i];
        }
        triangle.push_back(temp);
    }

    vector<vector<int>>DP;
    for(int i=0;i<n;i++){
        vector<int>temp(i+1,-1);
        DP.push_back(temp);
    }

    for(int i=0;i<n;i++){
        DP[n-1][i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up = DP[i+1][j];
            int dg = DP[i+1][j+1];
            DP[i][j] = min(up,dg)+triangle[i][j];
        }
    }
    cout<<DP[0][0];
    return 0;
}