#include<iostream>
using namespace std;

void k_multiples(int n,int k){
    if(k<1) return;
    k_multiples(n,k-1);
    cout<<n*k<<" ";
}

int main(){
    int n,k;
    cin>>n>>k;
    k_multiples(n,k);
    return 0;
}