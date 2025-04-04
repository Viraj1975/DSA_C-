#include<bits/stdc++.h>
using namespace std;

void find_factors(int n){
    for(int i=1;i<int(sqrt(n));i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0){
            cout<<n/i<<" ";
        }
    }
}

int main(){
    find_factors(60);
    return 0;
}