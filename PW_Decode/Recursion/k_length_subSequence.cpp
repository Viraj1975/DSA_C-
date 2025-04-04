#include<bits/stdc++.h>
using namespace std;

void k_length_subsequences(vector<int>v,int k,vector<vector<int>>&ans,vector<int>temp,int idx){
    if(idx==v.size()){
        if(temp.size()==k){
            ans.push_back(temp);
        }
        return;
    }
    if(temp.size()+(v.size()-idx)<k) return; // time complexity better ho jayegi
    k_length_subsequences(v,k,ans,temp,idx+1);
    temp.push_back(v[idx]);
    k_length_subsequences(v,k,ans,temp,idx+1);
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    vector<vector<int>>ans;
    vector<int>temp;
    k_length_subsequences(v,k,ans,temp,0);
    for(int i = 0; i < ans.size(); i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}