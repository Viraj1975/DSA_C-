#include<bits/stdc++.h>
using namespace std;

string DTB(int n){
    string result = "";
    while(n>0){
        if(n%2==0){
            result = '0'+result;
        }
        else result = '1'+result;
        n=n>>1;
    }
    return result;
}

int main(){
    cout<<DTB(19);
    return 0;
}