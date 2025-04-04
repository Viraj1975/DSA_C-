#include<iostream>
#include<stack>
using namespace std;

void delete_at_bottom(stack<int> &Original){
    stack<int>Temp;
    while(Original.size()!=1){
        int curr = Original.top();
        Original.pop();
        Temp.push(curr);
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
    delete_at_bottom(Original);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







