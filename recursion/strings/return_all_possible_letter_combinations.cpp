#include<iostream>
#include<vector>
using namespace std;

void Letter_Combinations(string &s,string s1,int idx,vector<string>v,vector<string>&result){
    if(idx==s.size()){
        result.push_back(s1);
        return;
    }
    int digit=s[idx]-'0';
    if(digit<=1){
        Letter_Combinations(s,s1,idx+1,v,result);
        return;
    }
    for(int j=0;j<v[digit].size();j++){
        Letter_Combinations(s,s1+v[digit][j],idx+1,v,result);
    }
    return;
}

int main(){
    vector<string>result;
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s;string s1="";
    cin>>s;
    int idx=0;
    Letter_Combinations(s,s1,idx,v,result);
    for (int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}