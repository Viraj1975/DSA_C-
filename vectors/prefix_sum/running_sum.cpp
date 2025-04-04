#include<iostream>
#include<vector>
using namespace std;

void running_sum(vector<int>&v){
    int sum;
    for(int i=0;i<v.size();i++){
        sum=0;
        for(int j=0 ; j<=i ; j++){
            sum+=v[j];
        }
        v[i]=sum;
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