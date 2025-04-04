#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int start_idx,int end_idx){
    int count = 0;
    int pivot_idx = (start_idx+end_idx)/2;
    int pivot = v[pivot_idx];

    for(int i=start_idx;i<=end_idx;i++){
        if(i==pivot_idx) continue;
        if(v[i]<=pivot) count++;
    }
    swap(v[pivot_idx],v[count+start_idx]);
    int low = start_idx;
    int high = end_idx;
    while(low<pivot_idx && high>pivot_idx){
        if(v[low]<=pivot) low++;
        if(v[high]>pivot) high--;
        else if(v[low]>pivot && v[high]<pivot){
            swap(v[low],v[high]);
            low++;high--;
        }
    }
    return count;
}

int Quick_sort(vector<int>&v,int start_idx,int end_idx,int k){
    if(start_idx<=end_idx){
        int partition_idx = partition(v,start_idx,end_idx);
        if(partition_idx+1>k){
            return Quick_sort(v,start_idx,partition_idx-1,k);
        }
        else if(partition_idx+1==k) return v[partition_idx];
        else{
            return Quick_sort(v,partition_idx+1,end_idx,k);
        }
    }
    return -1;
}

int main(){
    vector<int>v = {5,1,6,4,8,7,3,2};
    int n = v.size();
    int k;
    cin>>k;
    cout<<Quick_sort(v,0,n-1,k);
    return 0;
}