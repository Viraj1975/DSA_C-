#include<bits/stdc++.h>
using namespace std;

class Stack{
    int* arr;
    int capacity;
    int top;
    public:
        Stack(int c){
            this->top=-1;
            this->capacity=c;
            arr = new int[c];
        }

        void push(int val){
            if(this->top==this->capacity-1){
                cout<<"Stack is full";
                return;
            }
            this->top=this->top+1;
            this->arr[this->top] = val;
        }

        void pop(){
            if(this->top==-1) return;
            this->top=this->top-1;
        }

        int get_top(){
            if(this->top==-1) return INT_MIN;
            return this->arr[this->top];
        }

        int size(){
            return this->top+1;
        }

        void display(){
            for(int i=0;i<=this->top;i++){
                cout<<this->arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.pop();
    st.display();
    return 0;
}