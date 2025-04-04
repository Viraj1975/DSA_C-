#include<bits/stdc++.h>
using namespace std;

void permutations(string &str,int i){
    if(str.size()==i){
        cout<<str<<"\n";
        return;
    }
    unordered_set<char>s;
    for(int j=i;j<str.size();j++){
        if(s.count(str[j])) continue;
        s.insert(str[j]);
        
        swap(str[j],str[i]);
        permutations(str,i+1);
        swap(str[j],str[i]); // Backtracking Step
    }
    return;
}

int main(){
    string str;
    cin>>str;
    permutations(str,0);
    return 0;
}