#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int p=2;
    for(int i=1; i<=2*n-1; i++){
        if(i<=n){
            for(int k=1 ; k<=n-i ; k++){
                cout<<" ";
            }
            for(int j=0 ; j<2*i-1 ; j++){
                cout<<char('A'+j);
            }
        }
        else{
            for(int k=1 ; k<=i-n; k++){
                cout<<" ";
            }
            // for(int j=0 ; j<2*(2*n-i)-1; j++){
            for(int j=0 ; j<2*(i-p)-1; j++){
                cout<<char('A'+j);
            }
            p+=2;
        }
        cout<<endl;
    }
    return 0;
}
