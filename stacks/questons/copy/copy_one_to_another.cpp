#include<iostream>
#include<stack>
using namespace std;

stack<int> CopyStack(stack<int> &Original){
    stack<int>Temp;
    while(not Original.empty()){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
    }
    stack<int>Result;
    while(not Temp.empty()){
        int curr = Temp.top();
        Result.push(curr);
        Temp.pop();
    }
    return Result;
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);

    stack<int>result=CopyStack(Original);
    while(not result.empty()){
        int curr = result.top();
        cout<<curr<<endl;
        result.pop();
    }
    return 0;
}







