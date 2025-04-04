#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll DP[105][105];
ll g(vector<int>&colors,int i,int j){
    ll result = 0;
    for(int m=i;i<=j;m++){
        result = (result%100 + colors[m]%100)%100;
    }
    return result;
}
ll f(vector<int>&colors,int i,int j){
    if(i==j) return 0;
    if(DP[i][j]!=-1) return DP[i][j];

    ll result = INT_MAX;
    for(int k=i;k<=j-1;k++){
        result = min(result,f(colors,i,k)+f(colors,k+1,j)+g(colors,i,k)+g(colors,k+1,j));
    }
    return DP[i][j]=result;
}
int main(){
    int n;
    while(cin>>n){
        vector<int>colors;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            colors.push_back(x);
        }
        cout<<f(colors,0,colors.size()-1)<<endl;
        colors.clear();
        cin>>n;
    }
    return 0;
}