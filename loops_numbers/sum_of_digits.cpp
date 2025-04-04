#include<iostream>
using namespace std;

int main(){
    int num,sum=0,rem;
    cout<<"Enter the number : ";
    cin>>num;
    while(num>0){
        rem=num%10;
        num/=10;
        sum+=rem;;
    }
    cout<<sum;
    return 0;
}