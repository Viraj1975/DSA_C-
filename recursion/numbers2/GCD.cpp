#include<iostream>
using namespace std;

int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);

    // if(a==0) return b;
    // return GCD(b%a,a);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}