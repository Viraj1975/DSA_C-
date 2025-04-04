#include<iostream>
using namespace std;

string remove_occurrence(string &s,int size,int idx){
    if(idx==size) return "";
    string curr="";
    curr+=s[idx];
    return ((s[idx]=='a'?"":curr))+remove_occurrence(s,size,idx+1);    
}

int main(){
    int idx=0;
    string s;cin>>s;
    remove_occurrence(s,s.length(),idx);
    cout<<s;
    return 0;
}