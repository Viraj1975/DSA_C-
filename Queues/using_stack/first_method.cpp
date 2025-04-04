#include<iostream>
#include<stack>
using namespace std;

struct Queue{
    stack<int>s1;
    stack<int>s2;

    void Enqueue(int value){
        while(!s1.empty()){
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
        s1.push(value);
        while(!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
    } 

    int Dequeue(){
        if(s1.empty()){
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main(){
    Queue q;
    for(int i=0;i<5;i++){
        q.Enqueue(i);
    }
    q.Dequeue();
    return 0;
}