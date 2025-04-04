#include<iostream>
using namespace std;

// we can only move down or right

int Total_Path(int m,int n,int i,int j){
    if(i==m-1 and j==n-1) return 1;
    if(i>=m or j>=n) return 0;
    return Total_Path(m,n,i,j+1)+Total_Path(m,n,i+1,j);
}

int main(){
    int m,n;
    cin>>m>>n;
    int i=0,j=0;
    cout<<Total_Path(m,n,i,j);
    return 0;
}