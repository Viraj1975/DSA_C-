#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
};

class stack{
    Node* head;
    int capacity;
    int curr_size;
    public:
        stack(int c){
            this->capacity=c;
            curr_size=0;
            head = NULL;
        }

        bool is_empty(){
            return (this->head==NULL);
        }

        bool is_full(){
            return (this->curr_size==this->capacity);
        }

        void push(int data){
            if(this->curr_size==this->capacity){
                cout<<"Overflow"<<endl;
                return ;
            }
            Node* new_node = new Node(data);
            new_node->next=this->head;
            this->head=new_node;
            curr_size++;
        }

        int pop(){
            if(this->head==NULL){
                cout<<"Underflow"<<endl;
                return INT16_MIN;
            }
            Node* temp = this->head;
            int result = this->head->value;
            this->head=this->head->next;
            delete temp;
            curr_size--;
            return result;
        }
        int get_top(){
            return this->head->value;
        }
};

int main(){
    stack st(5);
    st.push(5);
    st.push(4);
    cout<<st.get_top()<<endl;
    st.push(3);
    st.push(1);
    cout<<st.get_top()<<endl;
    return 0;
}