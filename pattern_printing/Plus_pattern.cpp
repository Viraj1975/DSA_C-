#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    // i==row and j==column
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i==(n+1)/2 || j==(n+1)/2) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}