#include<bits/stdc++.h>
using namespace std;

int ways(int n,int i){
    if(i==n) return 1;
    if(i>n) return 0;
    return ways(n,i+1)+ways(n,i+2)+ways(n,i+3);
}

int main(){
    cout<<ways(3,0);
    return 0;
}