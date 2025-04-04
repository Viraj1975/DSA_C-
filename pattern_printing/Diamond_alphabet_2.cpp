#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int k=1 ; k<=n-i ; k++){
            cout<<" ";
        }
        for(int j=0 ; j<2*i-1 ; j++){
            cout<<char('A'+j);
        }
        cout<<endl;
    }
    for(int i=1; i<n; i++){
        for(int k=1 ; k<=i ; k++){
            cout<<" ";
        }
        for(int j=0 ; j<2*(n-i)-1 ; j++){
            cout<<char('A'+j);
        }
        cout<<endl;
    }

    return 0;
}
