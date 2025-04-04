#include<iostream>
using namespace std;

int main(){
    int power=1,base,result=1;
    cout<<"Enter the base : ";
    cin>>base;
    cout<<"Enter the power : ";
    cin>>power;
    while(power!=0){
        result*=base;
        power--;
    }
    cout<<result;
    return 0;
}