#include<iostream>
#include<vector>
using namespace std;

bool prefix_suffix_sum(vector<int>&v){
    int sumTotal=0;
    for(int i=0 ; i<v.size(); i++){
        sumTotal+=v[i];
    }
    int sumP=0,sumS;
    for(int i=0;i<v.size();i++){
        sumP+=v[i];
        sumS=sumTotal-sumP;
        if(sumP==sumS){
            return true;
        }
    }
    return false;
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
    prefix_suffix_sum(v);
    return 0;
}