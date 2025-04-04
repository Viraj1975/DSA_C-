#include<bits/stdc++.h>
using namespace std;

int find_unique(vector<int>v){
    int n = v.size();
    int t = v[0];
    for(int i=1;i<n;i++){
        t = t^v[i];
    }
    return t;
}

int main(){
    vector<int>v = {2,1,3,2,1,5,6,5,3};
    cout<<find_unique(v);
    return 0;
}