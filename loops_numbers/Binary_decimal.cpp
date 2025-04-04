#include<iostream>
using namespace std;

int main(){
    int binary,decimal=0,rem,power=1;
    cout<<"Enter the number in binary form : ";
    cin>>binary;
    while(binary!=0){
        rem=binary%10;
        decimal+=rem*power;
        power*=2;
        binary/=10;
    }
    cout<<decimal;
    return 0;
}