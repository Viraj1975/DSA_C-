#include<bits/stdc++.h>
using namespace std;

void cycleAlgo(vector<int>&nums){
    int n = nums.size();
    int i = 0;
    while(i<n){
        int correctIdx = nums[i];
        if(i==correctIdx) i++;
        else swap(nums[i],nums[correctIdx]);
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=i+1){
            cout<<i+1<<" is missing"<<endl;
        }
    }
}

int main(){
    vector<int>v = {5,1,0,3,4,2};
    cycleAlgo(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}