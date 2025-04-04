#include<iostream>
using namespace std;

class Queue{
    public:
        int f;
        int b;
        int *arr;
        int capacity;

        Queue(int capacity){
            this->f = 0;
            this->b = 0;
            this->capacity = capacity;
            this->arr = new int[capacity];
        }

        void push(int x){
            if(b==capacity){
                cout<<"Queue is FULL"<<endl;
                return;
            }
            arr[b] = x;
            b++;
        }

        void pop(){
            if(f-b==0){
                cout<<"Queue is empty"<<endl;
                return;
            }
            f++;
        }

        int front(){
            if(f-b==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[f];
        }

        int back(){
            if(f-b==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[b-1];
        }

        int size(){
            return b-f;
        }

        bool empty(){
            return (b-f==0);
        }

        void display(){
            for(int i=f;i<b;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Queue q(8);
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.push(40);
    q.push(50);
    q.display();
    q.push(60);
    q.push(70);
    q.pop();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.push(80);
    q.push(90);
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
}