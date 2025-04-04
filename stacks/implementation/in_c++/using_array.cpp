#include<iostream>
using namespace std;

class stack{
    int top;
    int capacity;
    int* arr;

    public:
        stack(int c){
            this->capacity=c;
            arr = new int[c];
            this->top=-1;
        }

        bool is_full(){
            return (this->top==this->capacity-1);
        }

        bool is_empty(){
            return (this->top==-1);
        }

        void push(int data){
            if(this->top==this->capacity-1){
                cout<<"Overflow";
                return;
            }
            this->top++;
            this->arr[this->top]=data;
        }

        int pop(){
            if(this->top==-1){
                cout<<"Underflow";
                return INT16_MIN;
            }
            return this->top--;
        }

        int get_top(){
            if(this->top==-1){
                cout<<"Underflow";
                return INT16_MIN;
            }
            return this->arr[this->top];
        } 

        int size(){
            return this->top+1;
        }

};

int main(){
    stack st(5);
    st.push(5);
    st.push(4);
    cout<<st.get_top()<<endl;
    st.push(3);
    st.push(2);
    cout<<st.get_top()<<endl;
    st.push(1);
    st.pop();
    cout<<st.get_top()<<endl;
    return 0;
}