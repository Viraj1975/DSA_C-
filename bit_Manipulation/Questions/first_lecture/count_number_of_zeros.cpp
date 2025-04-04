#include<iostream>
using namespace std;

int count_zeros(int n){
    // (n & n-1) have the same bits except the rightmost bit
    int count = 0;
    while(n!=0){
        n = (n & n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<count_zeros(n)<<endl;
}