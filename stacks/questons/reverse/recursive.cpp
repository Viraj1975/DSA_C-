#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom_recursive(stack<int>& st,int value){
    if(st.empty()){
        st.push(value);
        return;
    }
    int curr = st.top();
    st.pop();
    insert_at_bottom_recursive(st,value);
    st.push(curr);
}

void reverse(stack<int>& st){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom_recursive(st,curr);
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(not st.empty()){
        int curr = st.top();
        cout<<curr<<endl;
        st.pop();
    }
}