#include<bits/stdc++.h>
using namespace std;

int nearest_power_of_2(int x){
    // int t;
    // while(x>0){
    //     t = x;
    //     x = x & (x-1);
    // }
    // return t;


    // Method 2:

    x = x|(x>>1);
    x = x|(x>>2);
    x = x|(x>>4);
    x = x|(x>>8);
    x = x|(x>>16);
    
    return (x+1)>>1;
}

int main(){
    cout<<nearest_power_of_2(278);
    return 0;
}