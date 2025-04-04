#include<bits/stdc++.h>
using namespace std;

int flip_bits(int n){
    int t = n;
    n = n|(n>>1);
    n = n|(n>>2);
    n = n|(n>>4);
    n = n|(n>>8);
    n = n|(n>>16);

    // 10011001 ^ 11111111 = 01100110
    // 11111111 can be achieved using above method as well as brian kernighan's algorithm;
    return n^t;
}

int main(){
    cout<<flip_bits(5);
    return 0;
}