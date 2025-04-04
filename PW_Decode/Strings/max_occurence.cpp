#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int maxcount = 0;
    for(int i=0;i<s.size();i++){
        int count = 1;
        for(int j=i+1;j<s.size();j++){
            if(s[j]==s[i]){
                count++;
            }
        }
        maxcount = max(maxcount,count); 
    }

    for(int i=0;i<s.size();i++){
        int count = 1;
        for(int j=i+1;j<s.size();j++){
            if(s[j]==s[i]){
                count++;
            }
        }
        if(count==maxcount){
            cout<<s[i]<<" "<<count;
        } 
    }
    return 0;
}