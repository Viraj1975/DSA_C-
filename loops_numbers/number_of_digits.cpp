#include<iostream>
using namespace std;

int main(){
    int num,count=0;
    cout<<"Enter the number : ";
    cin>>num;
    while(num>0){
        num/=10;
        count++;
    }
    cout<<count;
    return 0;
}