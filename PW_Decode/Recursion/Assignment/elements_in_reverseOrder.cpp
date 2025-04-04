#include<bits/stdc++.h>
using namespace std;

void print(int i,vector<int>arr){
    if(i==arr.size()) return;
    print(i+1,arr);
    cout<<arr[i]<<" ";
}

int main(){
    vector<int>arr={1,2,3,4,5};
    print(0,arr);
    return 0;
}