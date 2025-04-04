#include<iostream>
using namespace std;

int main(){
    int mat1[][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for(int i=3;i>=0;i--){
        for(int j=0;j<4;j++){
            if(i%2==0) cout<<mat1[i][3-j]<<" ";
            else cout<<mat1[i][j]<<" ";
        }
    }
    return 0;
}