#include<iostream>
#include<stack>
using namespace std;

void insert_at_index(stack<int> &Original,int value,int index){
    stack<int>Temp;
    int size = Original.size();
    int count=0;
    while(count<(size-index)){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
        count++;
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
    Original.push(5);
    insert_at_index(Original,100,1);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







