#include<iostream>
using namespace std;

int sum_with_alternate_sign(int n){
    if(n==0) return 0;
    return sum_with_alternate_sign(n-1)+((n%2==0)?(-n):(n));
}

int main(){
    int n;
    cin>>n;
    cout<<sum_with_alternate_sign(n);
    return 0;
}