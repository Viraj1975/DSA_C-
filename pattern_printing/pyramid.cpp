#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter the value of row : ";
    cin>>row;
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=row-i ; j++){
            cout<<" ";
        }
        for(int j=1 ; j<=i ; j++){
            cout<<j;
        }
        for(int j=1 ; j<=i-1 ; j++){
            cout<<i-j;
        }
        cout<<endl;
    }

    return 0;
}