#include<bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    return 0;
}

int solve(int val1,int val2,int ch){
    if(ch=='+') return val1+val2;
    if(ch=='-') return val1-val2;
    if(ch=='*') return val1*val2;
    if(ch=='/') return val1/val2;
    return 0;
}

int evaluate(string str){
    stack<int>val;
    stack<char>op;

    for(int i=0;i<str.size();i++){
        if(str[i]==' ') continue;
        if(str[i]>=48 && str[i]<=57) val.push(str[i]-48);

        // if character is not a digit
        else{
            if(op.size()==0) op.push(str[i]);
            else if(str[i]=='(') op.push(str[i]);
            else if(op.top()=='(') op.push(str[i]);
            else if(str[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(str[i])>prio(op.top())) op.push(str[i]);
            else{
                while(op.size()>0 && prio(str[i])<=prio(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int res = solve(val1,val2,ch);
                    val.push(res);
                }
                op.push(str[i]);
            }
        }
    }
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int res = solve(val1,val2,ch);
        val.push(res);
    }
    return val.top();
}

int main(){
    string str;
    getline(cin,str);
    cout<<evaluate(str);
    return 0;
}