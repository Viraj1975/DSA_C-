#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = 1; 
    for(int i=1;i<=n;i++){
        int a = 1;
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        // for(int j=1;j<=i;j++){
        //     cout<<a++;
        // }
        // a-=2;
        // for(int j=i+1;j<=2*i-1;j++){
        //     cout<<a--;
        // }

        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=i-1;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}