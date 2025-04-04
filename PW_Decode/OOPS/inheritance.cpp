#include<bits/stdc++.h>
using namespace std;

class vehicle{ // Base Class , Parent Class
    public:
        int tyreSize;
        int engineSize;
        int lights;
        string companyName;
};

class Bike : public vehicle{ // Derived Class , child Class
    public:
        int handleSize;
        // Constructor
        Bike(int tyreSize){
            this->tyreSize = tyreSize;
            cout<<"hi"<<endl;
        }

        // Destructor
        ~Bike(){
            cout<<"bye"<<endl;
        } 
};

class car : public vehicle{
    public:
        int steeringSize;
};

// low se high security jaa sakte hai
// private cannot be accessed or inherited;
// protected cannot be accessed but is inherited;
// public can be accessed and inherited;


// TYPES OF INHERITANCE
// single inheritance : class B derives classA
// multi level inheritance : class B derives class A and class C derives class B .....
// multiple inheritance : multiple parent class and single child class;
// hierarchical inheritance : single parent class and mutiple child class;
// hybrid inheritance : mixture of all the inheritances;


// Diamond Problem

// class B derives class A and class C derives class A (hierarchical inheritance);  whereas class D derives class B and class C(multiple inheritance);
// here one problem arises that variable of a will be accessible from both parent classes of D i.e class B and class C ; which
// can be resolved by : 
    // ::(scope resolution operator) used in diamond problem;
    // better way will be to use virtual ; using virtual will make only one instance of class;

int main(){
    Bike bk1(12);
    Bike bk2(13);
    return 0;
}