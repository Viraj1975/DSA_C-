#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<"Enter Valid Value";
        return 0;
    }
    int a,b;
    a=0;
    b=1;
    int c;

    for(int i=2;i<=n;i++){
        c = a+b;
        a=b;
        b=c;
    }

    if(n<=1) cout<<n-1;
    else cout<<c;
    return 0;
}