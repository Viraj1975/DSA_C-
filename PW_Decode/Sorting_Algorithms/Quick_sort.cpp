#include<bits/stdc++.h>
using namespace std;

int Partition_index(vector<int>&v,int start,int end){
    int pivot = v[end];
    int idx = start;
    for(int i=start;i<end;i++){
        if(v[i]<pivot){
            swap(v[i],v[idx]);
            idx++;
        }
    }
    swap(v[idx],v[end]);
    return idx;
}

void Quick_sort(vector<int>&v,int start,int end){
    if(start>=end) return;
    int pi = Partition_index(v,start,end);
    Quick_sort(v,start,pi-1);
    Quick_sort(v,pi+1,end);
}

int main(){
    vector<int>v = {5,2,1,4,3,9,6,7,-1,10,15};
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    Quick_sort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}