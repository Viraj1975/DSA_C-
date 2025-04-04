#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    if(n%2!=0 && n!=1) return false; 
    if(n==0) return true;
    return check(n/2);
}

int main(){
    cout<<check(16);
    return 0;
}