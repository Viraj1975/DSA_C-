#include<bits/stdc++.h>
using namespace std;

class A{
    int a_private = 10;
    friend class B;
    public:
        friend void show(A &a);
};

void show(A &a){
    cout<<a.a_private<<endl;
}

int main(){
    A a;
    show(a);
    return 0;
}