#include<bits/stdc++.h>
using namespace std;
int ans;

bool canWeGo(int m,int n,int i,int j,vector<vector<int>>&grid){
    return i>=0 && j>=0 && i<m && j<n && grid[i][j]==0;
}

void f(int m,int n,int i,int j,vector<vector<int>>&grid){
    if(i==m-1 && j==n-1){
        ans+=1;
        return;
    }
    grid[i][j]=2;
    if(canWeGo(m,n,i+1,j,grid)){
        f(m,n,i+1,j,grid);
    }
    if(canWeGo(m,n,i,j+1,grid)){
        f(m,n,i,j+1,grid);
    }
    if(canWeGo(m,n,i-1,j,grid)){
        f(m,n,i-1,j,grid);
    }
    if(canWeGo(m,n,i,j-1,grid)){
        f(m,n,i,j-1,grid);
    }
    grid[i][j]=0;
}

int ways(int m,int n,vector<vector<int>>&grid){
    ans = 0;
    f(m,n,0,0,grid);
    return ans;
}


int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    cout<<ways(0,0,grid);
    return 0;
}