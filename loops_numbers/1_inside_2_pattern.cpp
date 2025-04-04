#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    int top=0;int a=1;int direction=0;
    int bottom=n-1;int left=0;int right=m-1;
    while(left<=right && top<=bottom){
        if(direction==0){
            for(int col=left ; col<=right ; col++){
                v[top][col]=a;
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                v[row][right]=a;
            }
            right--;
        }
        else if(direction==2){
            for(int col=right;col>=left;col--){
                v[bottom][col]=a;
            }
            bottom--;
        }
        else{
            for(int row=bottom;row>=top;row--){
                v[row][left]=a;
            }
            left++;
        }
        if(direction==3) a++;
        direction=(direction+1)%4;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}