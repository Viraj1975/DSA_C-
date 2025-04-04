#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

class Stack{
    Node* head = NULL;
    int size;
    public:
        Stack(){
            head=NULL;
            size=0;
        }

        void push(int val){
           Node* temp = new Node(val);
           temp->next=head;
           head=temp;
           size++;
        }

        void pop(){
            if(head==NULL) return;
            head=head->next;
            size--;
        }

        int get_top(){
            if(head==NULL) return INT16_MAX;
            return head->val;
        }

        void print(Node* temp){
            if(temp==NULL) return;
            print(temp->next);
            cout<<temp->val<<" ";
        }

        void display(){
            Node* temp = head;
            print(temp);
            cout<<endl;
        }
};

int main(){
    Stack st;
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