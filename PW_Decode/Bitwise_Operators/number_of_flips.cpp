#include<bits/stdc++.h>
using namespace std;

int number_of_flips(int num1,int num2){
    int t = num1^num2;
    return __builtin_popcount(t);
}

int main(){
    cout<<number_of_flips(23,31);
    return 0;
}