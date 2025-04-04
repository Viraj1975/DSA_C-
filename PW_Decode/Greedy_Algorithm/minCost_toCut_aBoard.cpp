#include<bits/stdc++.h>
using namespace std;

long long minCost(vector<long long>X,vector<long long>Y,int m,int n){
    sort(X.begin(),X.end(),greater<int>());
    sort(Y.begin(),Y.end()),greater<int>();
    long long minCost = 0;
    int HP = 1;
    int VP = 1;
    int i=0;
    int j=0;
    while(i<Y.size() && j<X.size()){
        if(Y[i] > X[j]){
            minCost+=Y[i]*VP;
            HP++;
            i++;
        }
        else{
            minCost+=X[i]*HP;
            VP++;
            j++;
        }
    }
    while(i<Y.size()){
        minCost+=Y[i]*VP;
        i++;
    }
    while(j<X.size()){
        minCost+=X[i]*HP;
        j++;
    }
    return minCost;
}
int main(){
    vector<long long>X;
    vector<long long>Y;
    int m,n;
    cout<<minCost(X,Y,m,n);
    return 0;
}