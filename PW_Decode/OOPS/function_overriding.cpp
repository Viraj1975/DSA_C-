#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int p,q;
        virtual void show(){ // makes the binding runtime;                            
            cout<<"A"<<endl; // ek virtual sab ke liye virtual matlab uske child classes ke liye;
        }
};

class B : public A{
    public:
        int r;
        void show(){
            cout<<"B"<<endl;
        }
};

class C : public B{
    public:
        int r;
        void show(){
            cout<<"C"<<endl;
        }
};

int main(){
    A a;
    // a.show();
    B b;
    // b.show();
    C c;

    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    // size increases on making a function virtual as vptr takes some space and the space is compiler dependent;
    // vptr stores vtable ; one table for each class and a vptr for each object;
    // achieves run time binding;


    // Compile time binding;
    // Run time binding - virtual;

    // accessing through scope resolution operator
    // b.A::show();


    // accessing through pointers;    
    // A *ap;
    // ap = &b; // pointer to parent can also store the address of child;
    // ap->show();

    // ap = &a;
    // ap->show();

    // ap = &c;
    // ap->show();
    return 0;
}