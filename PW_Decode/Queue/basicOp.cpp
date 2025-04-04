#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q){
    stack<int>s;
    int n = q.size();
    while(q.size()>0){
        int x = q.front();
        s.push(x);
        q.pop();
    }
    while(s.size()>0){
        int x = s.top();
        q.push(x);
        s.pop();
    }
}

void display(queue<int>&q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);
    reverse(q);
    display(q);
    return 0;
}