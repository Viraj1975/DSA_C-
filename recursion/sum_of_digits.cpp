#include <iostream>
using namespace std;

int sum1(int n){
    if(n>=0 && n<10) return n;
    return sum1(n/10)+n%10;
}

int main() {
    int n;
    cin>>n;
    cout<<sum1(n);
    return 0;
}