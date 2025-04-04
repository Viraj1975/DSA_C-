#include<iostream>
#include<vector>
using namespace std;

// time complexity : O(length of string)
// space complexity : O(1)

bool check_isomorphs(string &s1,string &s2){
    if (s1.size()!=s2.size()) return false; 
    vector<int>freq1(128,-1);
    vector<int>freq2(128,-1);
    for(int i=0;i<s1.size();i++){
        if(freq1[i]==freq2[i]){
            freq1[s1[i]]=i;
            freq2[s2[i]]=i;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if(!check_isomorphs(s1,s2)) cout<<"No";
    else cout<<"Yes";
    return 0;
}