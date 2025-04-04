#include<bits/stdc++.h>
using namespace std;
int count_inversions = 0;

void merge(vector<int>&v,int start,int mid,int end){
    // forming temporary vectors of reqd size;
    vector<int>a(mid-start+1);
    vector<int>b(end-mid);
    for(int i=0;i<a.size();i++){
        a[i] = v[start+i];
    }
    for(int i=0;i<b.size();i++){
        b[i] = v[mid+1+i];
    }
    
    int i = 0;
    int j = 0;
    int k = start;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            v[k++] = b[j++];
            count_inversions+=(a.size()-i);
        }
        else{
            v[k++] = a[i++];
        }
    }
    while(i<a.size()){
        v[k++] = a[i++];
    }
    while(j<b.size()){
        v[k++] = a[j++];
    }
}

//  instead of using global variable we use int return type for merge_sort function

void merge_sort(vector<int>&v,int start,int end){
    if(start>=end) return;
    int mid = start + (end-start)/2;

    // Recursively divide the vector
    merge_sort(v,start,mid);
    merge_sort(v,mid+1,end);

    // merge the divided vector
    merge(v,start,mid,end);
}

int main(){
    vector<int>v = {5,1,8,2,3};
    merge_sort(v,0,v.size()-1);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<count_inversions;
    return 0;
}