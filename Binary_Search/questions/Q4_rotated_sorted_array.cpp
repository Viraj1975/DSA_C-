#include<iostream>
#include<vector>
using namespace std;

// Time : O(N)

int rotated_sorted_array(vector<int>&v){
    int start=0;int end=v.size()-1;
    if(v.size()==1 || (v[start] < v[end])) return start;
    while(start<=end){
        int mid = start+(end-start)/2;
        // this eliminates chances of overflow
        if(v[mid]>v[mid+1]) return (mid+1);
        if(v[mid]<v[mid-1]) return mid;
        if(v[mid]>v[start]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    cout<<rotated_sorted_array(v);
    return 0;
}