#include<bits/stdc++.h>
using namespace std;

void print_permutations(string s,string temp){
    if(s==""){
        cout<<temp<<" ";
        return;
    }
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        print_permutations(left+right,temp+ch);
    }
}

int main(){
    string s;
    cin>>s;
    print_permutations(s,"");
    return 0;
}