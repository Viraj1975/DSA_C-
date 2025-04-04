#include<bits/stdc++.h>
using namespace std;

bool Palindrome(string s,int idx){
    if(idx==s.size()-1-idx){
        return true;
    }
    if(s[idx]==s[s.size()-1-idx]){
        return Palindrome(s,idx+1);
    }
    else return false;
}

int main(){
    string s = "malayabam";
    bool result = Palindrome(s,0);
    cout<<result;
    return 0;
}