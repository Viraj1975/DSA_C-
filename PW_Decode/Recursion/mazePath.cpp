#include<bits/stdc++.h>
using namespace std;

int NumberOfPaths(int i,int j,int m,int n){
    if(i==n || j==m){
        return 1;
    }
    return NumberOfPaths(i,j+1,m,n)+NumberOfPaths(i+1,j,m,n);
}

void printPath(int sr,int er,int sc,int ec,string s){
    if(sr==er || sc==ec){
        cout<<s<<endl;
        return;
    }
    // same work just different name for the parameters
    // prints the path from sr,sc to er,ec
    printPath(sr,er,sc+1,ec,s+'D'); // down
    printPath(sr+1,er,sc,ec,s+'R'); // right
}

int NumberOfPaths2(int m,int n){
    if(n==0 || m==0){
        return 1;
    }
    return NumberOfPaths2(m,n-1)+NumberOfPaths2(m-1,n);
}

void printPath2(int m,int n,string s){
    if(m==0 || n==0){
        cout<<s<<endl;
        return;
    }
    // same work just different name for the parameters
    // prints the path from sr,sc to er,ec
    printPath2(m,n-1,s+'D'); // down
    printPath2(m-1,n,s+'R'); // right
}

int main(){
    int m,n;
    cin>>m>>n;
    // cout<<NumberOfPaths(1,1,m,n)<<endl;
    // printPath(0,m,0,n,"");
    // cout<<NumberOfPaths2(m,n)<<endl;
    printPath(0,m,0,n,"");
    cout<<endl;
    printPath2(m,n,"");
    return 0;
}