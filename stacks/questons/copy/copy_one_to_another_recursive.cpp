#include<iostream>
#include<stack>
using namespace std;

void CopyStack(stack<int> &Original,stack<int>& Result){
    if(Original.empty()) return;
    int curr = Original.top();
    Original.pop();
    CopyStack(Original,Result);
    Result.push(curr);
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    stack<int>Result;
    CopyStack(Original,Result);
    while(not Result.empty()){
        int curr = Result.top();
        cout<<curr<<endl;
        Result.pop();
    }
    return 0;
}







