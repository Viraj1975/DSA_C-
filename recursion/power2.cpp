#include<iostream>
using namespace std;

int calP(int b,int p){
    if(p==0) return 1;
    if(p%2==0){ 
        int result=calP(b,p/2);
        return result*result;
    }else{
        int result=calP(b,(p-1)/2);
        return b*result*result;
    }
}

int main(){
    int base,power;
    cin>>base>>power;
    cout<<calP(base,power);
    return 0;
}

// O(log q);