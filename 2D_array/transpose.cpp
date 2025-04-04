#include<iostream>
using namespace std;

int main(){
    int r1,c1;
    cin>>r1>>c1;
    int Matrix[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>Matrix[i][j];
        }
    }
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            cout<<Matrix[j][i]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}