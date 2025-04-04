#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum = 0;
    if(n%2==0){
        sum = -n/2;
    }
    else{
        sum = 1 + n/2;
    }
    cout<<sum;
    return 0;
}