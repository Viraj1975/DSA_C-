#include<iostream>
using namespace std;

int main(){
    int r1,r2,c1,c2,sum;
    cin>>r1>>c1;
    cin>>r2>>c2;
    int Matrix1[r1][c1];
    int Matrix2[r2][c2];
    int result_Matrix[c1][r2]={0};
    if(c1==r2){
    for(int i=0 ; i<r1;i++){
        for(int j=0 ; j<c1; j++){
            cin>>Matrix1[i][j];
        }
    }
    for(int i=0 ; i<r2;i++){
        for(int j=0 ; j<c2; j++){
            cin>>Matrix2[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            sum=0;
            for(int k=0;k<c1;k++){
                sum+=Matrix1[i][k]*Matrix2[k][j];
            }
            result_Matrix[i][j]=sum;
        }
    }
    for(int i=0 ; i<c1;i++){
        for(int j=0 ; j<r2; j++){
            cout<<result_Matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    }
    else cout<<"Matrix Multiplication is not possible !!!!";
    return 0;
}