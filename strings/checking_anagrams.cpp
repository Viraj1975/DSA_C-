#include<iostream>
#include<vector>
using namespace std;

// we can also sort and compare the strings.
// time complexity : O(length of string)
// space complexity : O(1)

bool check_anagrams(string &s1,string &s2){
    if(s1.size()!=s2.size()) return false;    
    vector<int>freq1(26,0);
    for(int i=0;i<s1.size();i++){
        freq1[s1[i]-'a']++;
        freq1[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq1[i]!=0) return false;
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if(!check_anagrams(s1,s2)) cout<<"No";
    else cout<<"Yes";
    return 0;
}