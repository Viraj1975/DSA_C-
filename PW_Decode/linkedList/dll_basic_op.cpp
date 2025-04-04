#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class dll{
    public:
        Node* head;
        Node* tail;
        int size;

        dll(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        
};

int main(){

    return 0;
}