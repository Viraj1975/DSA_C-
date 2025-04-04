#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom_recursive(stack<int> &Original,int value){
    if(Original.empty()){
        Original.push(value);
        return;
    }
    int curr = Original.top();
    Original.pop();
    insert_at_bottom_recursive(Original,value);
    Original.push(curr);
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    insert_at_bottom_recursive(Original,100);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







