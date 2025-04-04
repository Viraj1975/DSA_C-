#include<iostream>
#include<stack>
using namespace std;

void delete_at_index_recursive(stack<int> &Original,int index,int count){
    if(count==(Original.size()-index-1)){
        Original.pop();
        return;
    }
    int curr = Original.top();
    Original.pop();
    delete_at_index_recursive(Original,index,count+1);
    Original.push(curr);
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    Original.push(5);
    Original.push(6);
    delete_at_index_recursive(Original,2,0);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}