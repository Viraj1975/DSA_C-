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


    vector<int>DP(n,-1);
    for(int i=0;i<n;i++){
        DP[i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int>temp(i+1,-1);
        for(int j=i;j>=0;j--){
            int down = DP[j];
            int dg = DP[j+1];
            temp[j] = min(down,dg)+triangle[i][j];
        }
        DP=temp;
    }
    cout<<DP[0];
    return 0;
}