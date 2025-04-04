#include<iostream>
using namespace std;

int GCD(int a,int b){
    if(a==b) return a;
    if(b>a) return GCD(b,a);
    return GCD(b,a-b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}