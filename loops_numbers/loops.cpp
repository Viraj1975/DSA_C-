#include<iostream>
using namespace std;
int main(){
    // while(condition){
    //   code    
    // }
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int i=1,sum=0;
    while(i<=n){
        sum+=i;
        i++;
    }
    cout<<sum;
    return 0;
}