#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int k){
    int start = 0;
    int end = k;
    int idx = -1;
    while(end>=start){
        int mid = start + (end-start)/2;
        long long sq = (long long)mid*mid;
        if(sq==k){
            return true;
        } 
        else if(sq>k){
            end = mid -1;
        }
        else start = mid + 1;
    }
    return false;
}

bool judgeSquareSum(int c) {
    for(int i=0;i<=c;i++){
        long long pdt = (long long)i*i;
        if(pdt>c) break;
        int num = c-i*i;
        if(isPerfectSquare(num)){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    cout<<judgeSquareSum(n);
    return 0;
}
