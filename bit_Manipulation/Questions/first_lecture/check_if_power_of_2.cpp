#include<iostream>
using namespace std;

bool check_if_power_of_2(int n){
    return (n && !(n & (n-1)));
}

int main(){
    int n;
    cin>>n;
    cout<<check_if_power_of_2(n);
}