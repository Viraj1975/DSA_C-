#include<bits/stdc++.h>
using namespace std;

void Generate_BS(string str,int n){
    if(str.size()==n){
        cout<<str<<" ";
        return;
    }
    Generate_BS(str+'0',n);
    if(str=="" || str[str.size()-1]=='0'){
        Generate_BS(str+'1',n);
    }
}

int main(){
    Generate_BS("",4);
    return 0;
}