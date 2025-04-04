#include<iostream>
#include<cmath>
using namespace std;

int check_armstrong(int n,int count){
    if(n==0) return 0;
    return pow(n%10,count)+check_armstrong(n/10,count);
}

int main(){
    int n;
    cin>>n;int count =0,temp=n;
    while(temp>0){
        temp/=10;count++;
    }
    int result=check_armstrong(n,count);
    if(result==n) cout<<"Yes";
    else cout<<"No";
    return 0;
}