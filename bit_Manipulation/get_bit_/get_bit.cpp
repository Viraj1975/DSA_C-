#include<iostream>
using namespace std;

bool get_bit(int n,int pos){
    return (n & (1<<pos))!=0;
}

int main(){
    int n,pos;
    cin>>n;
    cin>>pos;
    cout<<get_bit(n,pos);
}