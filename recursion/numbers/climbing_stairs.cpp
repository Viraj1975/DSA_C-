#include<bits/stdc++.h>
using namespace std;

int countWays(int i,int n){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    // total ways to reach n from 0 = ways to reach n from 1 + ways to reach n from 2;
    return countWays(i+1,n)+countWays(i+2,n);
}
int climbStairs(int n) {
    int i = 0;
    int No_ways = countWays(i,n);
    return No_ways;
}

int main(){
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}
