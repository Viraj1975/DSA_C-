#include<iostream>
using namespace std;

int main(){
    int n,sum=0,i=1;
    cout<<"Enter the value of n : ";
    cin>>n;
    do{
        sum+=i;
        i++;
    }
    while(i!=n);
    cout<<sum<<endl;
    return 0;
}