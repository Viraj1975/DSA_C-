#include<iostream>
#include<vector>
using namespace std;

void running_sum(vector<int>&v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    for(int i=0 ; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    running_sum(v);
    return 0;
}