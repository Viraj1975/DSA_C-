#include<bits/stdc++.h>
using namespace std;

int sum_of_oddNumbers(int a,int b){
    if(a%2==0){
        a++;
    }  
    if(a>b){
        return 0;
    }
    return a+sum_of_oddNumbers(a+2,b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<sum_of_oddNumbers(a,b);
    return 0;
}