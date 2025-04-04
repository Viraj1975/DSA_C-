#include<iostream>
#include<stack>
using namespace std;

stack<int> reverse_Stack(stack<int> &Original){
    stack<int>Temp;
    stack<int>Temp2;
    while(not Original.empty()){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
    }
    while(not Temp.empty()){
        int curr = Temp.top();
        Temp2.push(curr);
        Temp.pop();
    }
    while(not Temp2.empty()){
        int curr = Temp2.top();
        Original.push(curr);
        Temp2.pop();
    }
    return Original;
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);

    stack<int>result=reverse_Stack(Original);
    while(not result.empty()){
        int curr = result.top();
        cout<<curr<<endl;
        result.pop();
    }
    return 0;
}







