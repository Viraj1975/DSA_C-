#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter the value of row : ";
    cin>>row;
    for(int i=1 ; i<=row ; i++){
        for(int j=i ; j<=row ; j++){
            cout<<j;
        }
        for(int k=1 ; k<i; k++){
            cout<<k;
        }
        cout<<endl;
    }

    return 0;
}