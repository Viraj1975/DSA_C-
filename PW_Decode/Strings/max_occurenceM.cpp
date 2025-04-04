#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int count[26] = {0};
    for(int i=0;i<s.size();i++){
        count[s[i]-97]++;
    }
    int maxCount = 0;
    int idx =-1;
    for(int i=0;i<26;i++){
       if(count[i]>maxCount){
            maxCount = count[i];
       }
    }
    for(int i=0;i<26;i++){
        if(count[i]==maxCount){
            cout<<(char)(i+97)<<" "<<maxCount<<endl;
        }
    }
    return 0;
}