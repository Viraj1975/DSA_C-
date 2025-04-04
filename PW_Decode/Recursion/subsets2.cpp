#include<bits/stdc++.h>
using namespace std;

void  get_subsets(string temp,vector<string>&ans,string original,bool check,int idx){
    if(idx==original.size()){
        ans.push_back(temp);
        return;
    }
    char ch = original[idx];
    if(idx==original.size()-1){
        if(check==true) get_subsets(temp+ch,ans,original,true,idx+1);
        get_subsets(temp,ans,original,true,idx+1);
        return;
    }
    char dh = original[idx+1];
    if(ch==dh){
        if(check==true) get_subsets(temp+ch,ans,original,true,idx+1);
        get_subsets(temp,ans,original,false,idx+1);
    }
    else{
        if(check==true) get_subsets(temp+ch,ans,original,true,idx+1);
        get_subsets(temp,ans,original,true,idx+1);
    }
}

int main(){
    string s;
    getline(cin,s);
    vector<string>ans;
    get_subsets("",ans,s,true,0);
    for(string x: ans){
        cout<<x<<" ";
    }
    return 0;
}

