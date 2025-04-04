#include<bits/stdc++.h>
using namespace std;

int count_set_bits_1(int n){
    return __builtin_popcount(n);
}

int count_set_bits_2(int n){
    int count = 0;
    while(n>0){
        n = n&(n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<count_set_bits_1(453);
    cout<<endl<<count_set_bits_2(453);
    return 0;
}