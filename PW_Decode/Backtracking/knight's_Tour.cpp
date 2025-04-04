#include<bits/stdc++.h>
using namespace std;

int ans;

bool canWeGo(int n,int i,int j,vector<vector<int>>&grid){
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==-1;
}

void display(vector<vector<int>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void f(int n,int i,int j,vector<vector<int>>&grid,int count){
    if(count==n*n-1){
        grid[i][j]=count;
        cout<<endl;
        display(grid,n);
        grid[i][j]=-1;
        return;
    }

    if(canWeGo(n,i+2,j+1,grid)){
        grid[i+2][j+1]=count;
        f(n,i+1,j,grid,count+1);
        grid[i+2][j+1]=-1;
    }
    if(canWeGo(n,i+2,j-1,grid)){
        grid[i+2][j-1]=count;
        f(n,i,j+1,grid,count+1);
        grid[i+2][j-1]=-1;
    }
    if(canWeGo(n,i-2,j+1,grid)){
        grid[i-2][j+1]=count;
        f(n,i-2,j+1,grid,count+1);
        grid[i-2][j+1]=-1;
    }
    if(canWeGo(n,i-2,j-1,grid)){
        grid[i-2][j-1]=count;
        f(n,i-2,j-1,grid,count+1);
        grid[i-2][j-1]=-1;
    }
    if(canWeGo(n,i+1,j-2,grid)){
        grid[i+1][j-2]=count;
        f(n,i+1,j,grid,count+1);
        grid[i+1][j-2]=-1;
    }
    if(canWeGo(n,i-1,j-2,grid)){
        grid[i-1][j-2]=count;
        f(n,i,j+1,grid,count+1);
        grid[i-1][j-2]=-1;
    }
    if(canWeGo(n,i-1,j+2,grid)){
        grid[i-1][j+2]=count;
        f(n,i-1,j,grid,count+1);
        grid[i-1][j+2]=-1;
    }
    if(canWeGo(n,i+1,j+2,grid)){
        grid[i+1][j+2]=count;
        f(n,i,j-1,grid,count+1);
        grid[i+1][j+2]=-1;
    }
}

int KnightsTour(int n,vector<vector<int>>&grid){
    ans = 0;
    f(n,0,0,grid,0);
    return ans;
}


int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>>grid(m,vector<int>(n,-1));
    cout<<KnightsTour(0,grid);
    return 0;
}