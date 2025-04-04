#include<iostream>
#include<stack>
using namespace std;

void delete_at_index(stack<int> &Original,int index){
    stack<int>Temp;
    int size = Original.size();
    int count=0;
    while(count<(size-index-1)){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
        count++;
    }
    Original.pop();
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
    delete_at_index(Original,2);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







