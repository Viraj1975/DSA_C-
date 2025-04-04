#include<bits/stdc++.h>
using namespace std;

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

void interleave(queue<int>&q){
    int n = q.size();
    stack<int>st;

    // first half in stack
    for(int i=0;i<n;i++){
        int x = q.front();
        q.pop();
        if(i<n/2){
            st.push(x);
        }else{
            q.push(x);
        }
    }

    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }

    // second half in stack 
    for(int i=0;i<n;i++){
        int x = q.front();
        q.pop();
        if(i<n/2){
            st.push(x);
        }else{
            q.push(x);
        }
    }

    // using stack and queue

    while(st.size()>0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

    // reverse Queue
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
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
    interleave(q);
    display(q);
    return 0;
}