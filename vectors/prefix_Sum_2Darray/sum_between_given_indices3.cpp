#include<iostream>
#include<vector>
using namespace std;

void give_Sum(vector<vector<int>>&v,int l1,int r1,int l2,int r2){
    for(int i=0; i<v.size();i++){
        for(int j=1;j<v[0].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
    for(int i=1; i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j]+=v[i-1][j];
        }
    }
    int sum=0;
    int top_sum=0,left_sum=0,top_left_sum=0;
    if(l1!=0) top_sum=v[l1-1][r2];
    if(r1!=0) left_sum=v[l2][r1-1];
    if(r1!=0 && l1!=0) top_left_sum=v[l1-1][r1-1];
    sum=v[l2][r2]-top_sum-left_sum+top_left_sum;
    cout<<sum;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int l1,r1,l2,r2;
    cin>>l1>>r1;
    cin>>l2>>r2;
    give_Sum(v,l1,r1,l2,r2);
    return 0;
}