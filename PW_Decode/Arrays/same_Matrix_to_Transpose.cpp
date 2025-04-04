#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Printing Transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n-1) break;
            if(j>i){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}