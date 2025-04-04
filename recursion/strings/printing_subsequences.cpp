#include<iostream>
#include<vector>
using namespace std;

void print_subsequence(string s,string s1,vector<string>&S,int idx){
    if(idx==s.size()){
        S.push_back(s1);
        return;
    }
    print_subsequence(s,s1+s[idx],S,idx+1);
    print_subsequence(s,s1,S,idx+1);
}
int main(){
    string s;int idx=0;
    cin>>s;string s1="";vector<string>S;
    print_subsequence(s,s1,S,idx);
    for(int i=0;i<S.size();i++){
        cout<<S[i]<<" ";
    }
    return 0;
}