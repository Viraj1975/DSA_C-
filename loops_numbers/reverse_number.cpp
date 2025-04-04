#include<iostream>
using namespace std;

int main(){
    int num,rem,rev_num=0;
    cout<<"Enter the number : ";
    cin>>num;
    while(num>0){
        rem=num%10;
        rev_num=rev_num*10+rem; 
        num/=10;
    }
    cout<<rev_num;
    return 0;
}