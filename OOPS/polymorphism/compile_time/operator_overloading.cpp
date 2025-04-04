#include<iostream>
using namespace std;

class add{
public:
    int real;
    int img;
    add(int x,int y){
        real=x;
        img=y;
    }
    add operator+(const add &c){
        return add(real+c.real,img+c.img);
    }
};

int main(){
    add c1(1,4);
    add c2(2,8);
    add c3=c1+c2;
    cout<<c3.real<<" i"<<c3.img<<endl;
    return 0;
}