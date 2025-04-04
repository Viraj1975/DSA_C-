#include<iostream>
using namespace std;

int main(){
    int mat1[][3] = {1,2,3,4,5,6,7,8,9};
    int mat2[][3] = {1,2,3,4,5,6,7,8,9};
    int matR[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum = 0;
            for(int k=0;k<3;k++){
                sum+=mat1[i][k]*mat2[k][j];
            }
            matR[i][j] = sum;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matR[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}