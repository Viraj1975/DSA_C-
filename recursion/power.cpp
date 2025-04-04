#include<iostream>
using namespace std;

int calP(int b,int p){
    if(p==0) return 1;
    return b*calP(b,p-1);
}

int main(){
    int base,power;
    cin>>base>>power;
    cout<<calP(base,power);
    return 0;
}

// O(q);