#include<bits/stdc++.h>
using namespace std;

void print_subsets(string sub,string str,int i){
    if(i==str.size()){
        cout<<sub<<" ";
        return;
    }
    print_subsets(sub+str[i],str,i+1);
    print_subsets(sub,str,i+1);
}

int main(){
    string s;
    getline(cin,s);
    print_subsets("",s,0);
    return 0;
}