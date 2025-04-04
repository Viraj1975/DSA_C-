#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    stringstream ss(str);
    string temp;
    vector<string>s;

    while(ss>>temp){
        s.push_back(temp);
    }
    sort(s.begin(),s.end());
    int maxCount = 1;
    for(int i=0;i<s.size()-1;i++){
        int count = 1;
        int j = i+1;
        while(j<s.size() && s[j]==s[i]){
            count++;
            j++;
        }
        if(count>=maxCount){
            maxCount = count;  
        }
        i=j;
    }
    int count = 1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]) count++;
        else count=1;
        if(count==maxCount){
            cout<<s[i]<<" "<<maxCount<<endl;
        }
    }
    return 0;
}