#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter the value of row : ";
    cin>>row;
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=i ; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}