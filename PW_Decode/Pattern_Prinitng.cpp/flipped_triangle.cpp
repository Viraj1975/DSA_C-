#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k = 1;
    for(int i=1;i<=n;i++){
    
        for(int j=1;j<=n;j++){
            if((i+j)>=n+1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        // for(int k = 1;k<=i;k++){
        //     cout<<"*";
        // }

        // for(int k = 1;k<=i;k++){
        //     cout<<k<<" ";
        // }

        cout<<endl;
    }
    return 0;
}