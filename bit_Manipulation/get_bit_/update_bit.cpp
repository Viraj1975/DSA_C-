#include<iostream>
using namespace std;

int update_bit(int n,int pos,int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | value<<pos);
}

int main(){
    int n,pos,value;
    cin>>n;
    cin>>pos;
    cin>>value;
    
    cout<<update_bit(n,pos,value);
}