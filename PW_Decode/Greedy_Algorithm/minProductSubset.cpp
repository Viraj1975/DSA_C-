#include<bits/stdc++.h>
using namespace std;

int minProductSubset(vector<int>&arr){
    int zc = 0;
    int nc = 0;
    int minP = INT_MAX;
    int maxN = INT_MIN;
    long long product = 1;
    for(int x:arr){
        if(x<0){
            nc++;
            maxN = max(maxN,x);
        }
        if(x==0) zc++;
        else product*=x;
        if(x>0){
            minP = min(minP,x);
        }
    }

    if(nc==0){
        if(zc==0){
            return minP;
        }
        else{
            return 0;
        }
    }
    else{
        if(nc%2==0){
            return product/(maxN);
        }
        else return product;
    }
    return 0;
}

int main(){
    cout<<7/(-2);
    return 0;
}