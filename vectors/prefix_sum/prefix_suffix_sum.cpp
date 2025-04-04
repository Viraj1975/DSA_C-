#include<iostream>
#include<vector>
using namespace std;

void prefix_suffix_sum(vector<int>&v){
    bool tell=false;
    int sumP=0;
    for(int i=0;i<v.size();i++){
        int sumS=0;
        sumP+=v[i];
        for(int j=i+1 ; j<=v.size() ; j++){
            sumS+=v[j];
        }
        if(sumP==sumS){
            tell=true;
            break;
        }
    }
    if(tell) cout<<"Yes";
    else cout<<"No";
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
    prefix_suffix_sum(v);
    return 0;
}