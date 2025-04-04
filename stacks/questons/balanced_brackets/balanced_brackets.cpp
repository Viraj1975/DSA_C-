#include<iostream>
#include<stack>
using namespace std;

bool check_balanced_brackets(string &s){
    stack<char>st;
    int size = s.size();
    for(int i=0;i<size;i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(s[i]==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else if(s[i]=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cout<<"Enter the brackets : ";
    cin>>s;
    cout<<check_balanced_brackets(s);
    return 0;
}