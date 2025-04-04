#include<bits/stdc++.h>
using namespace std;

int find_sqrt(int k){
    int start = 0;
    int end = k;
    while(end>=start){
        int mid = start + (end-start)/2;
        if(mid*mid==k){
            return mid;
        }
        else if(mid*mid>k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return end;
}

int main(){
    int k;
    cin>>k;
    cout<<find_sqrt(k);
    return 0;
}