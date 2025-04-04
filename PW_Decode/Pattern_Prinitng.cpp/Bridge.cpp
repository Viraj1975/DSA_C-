#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nsp = 1;
    int nst = n-1;

    // int m = n - 1;

    for(int i=1;i<=n;i++){
       if(i==1){
            for(int j=1;j<=2*n-1;j++){
                cout<<"*";
            } 
       }
       else{
            for(int j=1;j<=nst;j++){
                cout<<"*";
            }
            for(int j=1;j<=nsp;j++){
                cout<<" ";
            }
            for(int j=1;j<=nst;j++){
                cout<<"*";
            }
            nsp+=2;nst--;
       }
       cout<<endl;
        
    }
    return 0;
}