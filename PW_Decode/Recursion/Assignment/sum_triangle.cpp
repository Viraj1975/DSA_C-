#include<bits/stdc++.h>
using namespace std;

void print_triangleSum(vector<int>v,int n){
    if(n==0) return;
    for(int i=0;i<n-1;i++){
        v[i]=v[i]+v[i+1];
        cout<<v[i]<<" ";
    }
    cout<<endl;
    print_triangleSum(v,n-1);
}

int main(){
    vector<int>v = {5,4,3,2,1};
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    print_triangleSum(v,n);
    return 0;
}