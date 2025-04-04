#include<iostream>
#include<vector>
#include<string>
using namespace std;

void sort_string(string &s){
    // this makes the count sort stable
    // otherwise there is no need to calculate cummulative freq and traverse from back . 
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++){
        int ele = s[i] - 'a';
        freq[ele]++;
    }
    for(int i=1;i<26;i++){
        freq[i]+=freq[i-1];
    }
    vector<string>ans(s.size());
    for(int i=s.size()-1;i>=0;i--){
        ans[--freq[s[i]-'a']]=s[i];
    }
    string sorted_str;
    for(int i=0;i<s.size();i++){
        sorted_str+=ans[i];
    }
    s=sorted_str;
    return;
}

int main(){
    string s;
    cout<<"Enter string : ";
    getline(cin,s);
    sort_string(s);
    cout<<"Sorted string : ";
    cout<<s;
    return 0;
}