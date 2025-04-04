#include<bits/stdc++.h>
using namespace std;

void reverseK(queue<int>&q,int k){
    stack<int>s;
    int n = q.size();
    for(int i=0;i<k;i++){
        int x = q.front();
        q.pop();
        s.push(x);
    }
    while(s.size()>0){
        int x = s.top();
        q.push(x);
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        int x = q.front();
        q.pop();
        q.push(x);
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
    reverseK(q,2);
    display(q);
    return 0;
}