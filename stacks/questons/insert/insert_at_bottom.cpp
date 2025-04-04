#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &Original,int value){
    stack<int>Temp;
    while(not Original.empty()){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
    }
    Original.push(value);
    stack<int>Result;
    while(not Temp.empty()){
        int curr = Temp.top();
        Original.push(curr);
        Temp.pop();
    }
    return;
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    insert_at_bottom(Original,100);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







