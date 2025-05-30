#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// time complexity : O(n) where n is the length of decoded string .
// space complexity : O(n) where n is the length of decoded string .

string decode_string(string &s){
    string result="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=']'){
            result+=s[i];
        }
        else{
            string str = "";
            while(!result.empty() && result.back()!='['){
                str.push_back(result.back());
                result.pop_back();
            }
            reverse(str.begin(),str.end());
            result.pop_back();
            string num;
            while(!result.empty() && (result.back()>='0' && result.back()<='9')){
                num.push_back(result.back());
            }
            reverse(num.begin(),num.end());
            int int_num = stoi(num);
            while(int_num){
                result+=str;
                int_num--;
            }
        }
    }
    return result;
}

int main(){
    string s;
    cin>>s;
    cout<<decode_string(s);
    return 0;
}