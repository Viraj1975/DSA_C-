#include<iostream>
#include<stack>
using namespace std;

void delete_at_bottom_recursive(stack<int> &Original){
    if(Original.size()==1){
        Original.pop();
        return;
    }
    int curr = Original.top();
    Original.pop();
    delete_at_bottom_recursive(Original);
    Original.push(curr);
}

int main(){
    stack<int>Original;
    Original.push(1);
    Original.push(2);
    Original.push(3);
    Original.push(4);
    Original.push(5);
    delete_at_bottom_recursive(Original);
    while(not Original.empty()){
        int curr = Original.top();
        cout<<curr<<endl;
        Original.pop();
    }
    return 0;
}







