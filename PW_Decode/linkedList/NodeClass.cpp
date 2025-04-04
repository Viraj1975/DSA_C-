#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

int main(){
    Node a;
    a.val = 10;
    Node b;
    b.val = 20;
    Node c;
    c.val = 30;

    a.next=&b;
    b.next=&c;
    c.next=NULL;

    Node temp = a;
    while(1){
        cout<<temp.val<<"->";
        if(temp.next==NULL) break;
        temp = *(temp.next);
    }
    cout<<"NULL";
    return 0;
}