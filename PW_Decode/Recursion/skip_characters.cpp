#include<bits/stdc++.h>
using namespace std;

void skip_char(string ans,string str,int idx){
    if(idx==str.size()){
        cout<<ans<<endl;
        return;
    }
    if(str[idx]=='a') skip_char(ans,str,idx+1);
    else skip_char(ans+str[idx],str,idx+1);
    // can be solved with 2 parameters using index
}

int main(){
    string str;
    getline(cin,str);
    skip_char("",str,0);
    return 0;
}