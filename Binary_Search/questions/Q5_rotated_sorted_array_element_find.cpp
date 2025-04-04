#include<iostream>
#include<vector>
using namespace std;

// Time : O(N)

int rotated_sorted_array(vector<int>&v,int x){
    int start=0;int end=v.size()-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        // this eliminates chances of overflow
        if(v[mid]==x) return mid;
        if(v[mid]>=v[start]){
            if(x>=v[start] and x<=v[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(x<=v[end] and x>=v[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int N;int x;
    cin>>N;
    vector<int>v(N);
    cin>>x;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    cout<<rotated_sorted_array(v,x);
    return 0;
}