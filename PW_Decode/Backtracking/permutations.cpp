#include<bits/stdc++.h>
using namespace std;

void permutations(string str,string temp){
    if(str.size()==0){
        cout<<temp<<" ";
        return;
    }
    for(int j=0;j<str.size();j++){
        char ch = str[j];
        string rem = str.substr(0,j)+str.substr(j+1);
        permutations(rem,temp+ch);
    }
    return;
}

int main(){
    string str;
    cin>>str;;
    permutations(str,{});
    return 0;
}