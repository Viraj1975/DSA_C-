#include<iostream>
#include<stack>
using namespace std;

struct Queue{
    stack<int>s1;
    stack<int>s2;

    void Enqueue(int value){
        s1.push(value);
    } 

    int Dequeue(){
        int x = s1.top();
        if(s1.empty() && s2.empty()){
            return -1;
        } 
        if(s2.empty()){
            while(!s1.empty()){
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
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