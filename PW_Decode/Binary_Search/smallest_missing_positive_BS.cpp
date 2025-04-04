#include<bits/stdc++.h>
using namespace std;

// O(n);
// it will run for distinct as well as unique integers.
int find_first_missing_positive(vector<int>v){
    int start = 0;
    int end = v.size()-1;

    while(end>=start){
        int mid = start + (end-start)/2;
        if(v[mid]==mid){
            start=mid+1;
        }
        // else{
        //     if(mid>0 && v[mid]!=v[mid-1]+1){
        //         return mid;
        //     }
        //     else{
        //         end=mid-1;
        //     }
        // }

        else{
            end = mid - 1;
        }
    }
    // return v.back()+1;
    return start;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<find_first_missing_positive(v);
    return 0;
}