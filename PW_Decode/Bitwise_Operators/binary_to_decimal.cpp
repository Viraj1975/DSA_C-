#include<bits/stdc++.h>
using namespace std;

int BTD(string s){
    int result = 0;
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        int num = s[i]-'0';
        result+=num*(1<<(n-i-1));
    }
    return result;
}

int main(){
    string s = "011101";
    cout<<BTD(s);
    return 0;
}