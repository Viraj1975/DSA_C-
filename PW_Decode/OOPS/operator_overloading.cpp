#include<bits/stdc++.h>
using namespace std;

// we can also achieve operator overloading using friend function.

class complexNumber{
    public: 
        int img;
        int real;

        complexNumber add(complexNumber &c2){
            complexNumber c3;
            c3.img = c2.img + this->img;
            c3.real = c2.real + this->real;
            return c3;
        }

        complexNumber operator + (complexNumber &c2){
            complexNumber c3;
            c3.img = c2.img + this->img;
            c3.real = c2.real + this->real;
            return c3;
        }
};

int main(){
    complexNumber c1;
    complexNumber c2;
    c1.img = 5;
    c1.real = 7;
    c2.img = 16;
    c2.real = 14;
    complexNumber c3 = c1.add(c2);
    cout<<c3.real<<" "<<c3.img<<endl;

    complexNumber c4 = c1+c2;
    cout<<c4.real<<" "<<c4.img;

    // . , ?: , :: and sizeof() operators cannot be overloaded;
    return 0;
}