#include<iostream>
#include<stack>
using namespace std;

void insert_at_index_recursive(stack<int> &Original,int value,int index,int count){
    if(count==(Original.size()-index)){
        Original.push(value);
        return;
    }
    int curr = Original.top();
    Original.pop();
    insert_at_index_recursive(Original,value,index,count+1);
    Original.push(curr);
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    Original.push(5);
    insert_at_index_recursive(Original,100,2,0);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







