#include<iostream>
#include<vector>
#define MAX 500
using namespace std;

int mul(int x,int res[],int res_size){
    int carry = 0;
    for(int i=0;i<res_size;i++){
        int prod = res[i]*x + carry;
        res[i] = prod % 10;
        carry = prod/10;
    }
    while(carry){
        res[res_size] = carry % 10;
        res_size++;
        carry/=10;
    }
    return res_size;
}

int factorial(int x){
    int res[500];
    int res_size = 1;
    res[0]=1;

    for(int i=2;i<=x;i++){
        res_size = mul(i,res,res_size);
    }

    for(int i=res_size-1;i>=0;i--){
        cout<<res[i];
    }
}

int main(){
    factorial(100);
    return 0;
}