#include<iostream>
using namespace std;

void increasing_sequence(int n){
    if(n<1) return;
    increasing_sequence(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cin>>n;
    increasing_sequence(n);
    return 0;
}