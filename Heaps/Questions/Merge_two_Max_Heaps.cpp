#include<iostream>
#include<vector>
using namespace std;

void Heapify(int i,vector<int>&v){
    int LC_index = 2*i+1;
    int RC_index = 2*i+2;
    int largest = i;

    if(LC_index<v.size() && v[LC_index]>v[largest]){
        largest = LC_index;
    }
    if(RC_index<v.size() && v[RC_index]>v[largest]){
        largest = RC_index;
    }
    if(largest!=i){
        swap(v[largest],v[i]);
        Heapify(largest,v);
    }
}

void buildHeap(vector<int>&v){
    for(int i=v.size()/2-1;i>=0;i--){
        Heapify(i,v);
    }
}

vector<int> Merge_Heaps(vector<int>v1,vector<int>v2){
    vector<int>v;
    for(int x:v1){
        v.push_back(x);
    }
    for(int x:v2){
        v.push_back(x);
    }
    buildHeap(v);
    return v;
}

int main(){
    return 0;
}