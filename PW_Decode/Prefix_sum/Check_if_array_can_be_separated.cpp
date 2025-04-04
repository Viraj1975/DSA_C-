#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }

    for(int i=0;i<v.size();i++){
        if(2*v[i]==v[v.size()-1]) return true;
    }
    return false;
}

int main(){
    vector<int>v = {1,2,3,4,5,6,9};
    cout<<check(v);
    return 0;
}