#include<bits/stdc++.h>
using namespace std;

bool isPS(int k){
    int sq = sqrt(k)*sqrt(k);
    if(sq==k) return true;
    else return false;
}

bool judgeSquareSum(int c) {
    int x = 0;
    int y = c;
    while(y>=x){
        if(isPS(x) && isPS(y)){
            return true;
        }
        else if(!isPS(y)){
            y = sqrt(y)*sqrt(y);
            x = c - y;
        }
        else{
            x = (sqrt(x)+1)*(sqrt(x)+1);
            y = c - x;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    judgeSquareSum(n);
    return 0;
}
