#include<iostream>
#include<vector>
using namespace std;

int binary_2D(vector<vector<int>>&v,int x){
    int n=v.size();int m=v[0].size();
    int start=0;int end=n*m-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int a=mid/m;int b=mid%m;
        if(v[a][b]==x) return 1;
        else if(v[a][b]>x) end=mid-1;
        else start=mid+1;
    }
    return 0;
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
    int x;
    cin>>x;
    cout<<binary_2D(v,x);
    return 0;
}