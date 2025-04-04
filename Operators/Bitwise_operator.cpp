#include<iostream>
using namespace std;

int main(){
    // ~ bitwise complement
    // ~ 1 = 0
    // ~ 0 = 1

    // << left shift
    // number multiplied by 2
    // 0100 << 1 = 1000
    
    // >> right shift
    // number divided by 2
    // 0100 >> 1 = 0010

    // int x = 2;
    // x = x>>1;
    // cout<<x<<endl;

    // x = x>>1;
    // cout<<x<<endl;
    int x;
    cin>>x;
    x=x<<1;
    cout<<x<<endl;
    
    return 0;
}