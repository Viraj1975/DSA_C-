#include<iostream>
using namespace std;

class parent{
public:
    virtual void print(){
        cout<<"parent class ";
    }
    void show(){
        cout<<"parent class";
    }
};

class child: public parent{
public:
    void print(){
        cout<<"child class ";
    }
    void show(){
        cout<<"child class";
    }
};


int main(){
    parent *p;
    child c;
    p=&c;
    p->print();
    p->show();
    return 0;
}