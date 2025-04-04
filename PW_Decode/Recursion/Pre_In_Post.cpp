#include<bits/stdc++.h>
using namespace std;

void Pre_In_Post(int n){
    if(n==0) return;
    cout<<n<<" ";
    Pre_In_Post(n-1);
    cout<<n<<" ";
    Pre_In_Post(n-1);
    cout<<n<<" ";
}

int main(){
    Pre_In_Post(3);
    return 0;
}