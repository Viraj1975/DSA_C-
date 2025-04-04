#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n;cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    
    int minr = 0;
    int maxr = m-1;
    int minc =  0;
    int maxc = n-1;
    
    while(minc<=maxc && minr<=maxr){
        // right
        for(int i=minc;i<=maxc;i++){
            cout<<mat[minr][i]<<" ";
        }
        minr++;
        if(minr>maxr || minc>maxc) break;

        // down
        for(int i=minr;i<=maxr;i++){
            cout<<mat[i][maxc]<<" ";
        }
        maxc--;
        if(minr>maxr || minc>maxc) break;

        // left
        for(int i=maxc;i>=minc;i--){
            cout<<mat[maxr][i]<<" ";
        }
        maxr--;
        if(minr>maxr || minc>maxc) break;

        // top
        for(int i=maxr;i>=minr;i--){
            cout<<mat[i][minc]<<" ";
        }
        minc++;
    }
    
    return 0;
}