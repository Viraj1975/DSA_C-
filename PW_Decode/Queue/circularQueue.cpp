#include<iostream>
using namespace std;

class Queue{
    public:
        int f;
        int b;
        int *arr;
        int size;
        int capacity;

        Queue(int capacity){
            this->f = 0;
            this->b = 0;
            this->capacity = capacity;
            this->arr = new int[capacity];
            this->size=0;
        }

        void push(int x){
            if(size==capacity){
                cout<<"Queue is FULL"<<endl;
                return;
            }
            arr[b] = x;
            b++;
            size++;
        }

        void pop(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return;
            }
            f++;
            size--;
        }

        int front(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[f];
        }

        int back(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[b-1];
        }

        int size(){
            return size;
        }

        bool empty(){
            return (size==0);
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
    // cout<<q.size()<<endl;
}