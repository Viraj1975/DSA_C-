#include<bits/stdc++.h>
using namespace std;

int print_idx(int i,vector<int>arr,int k){
    if(i==arr.size()) return -1;
    if(arr[i]==k) return i;
    return print_idx(i+1,arr,k);
}

int main(){
    vector<int>arr={1,2,3,4,5};
    cout<<print_idx(0,arr,4);
    return 0;
}