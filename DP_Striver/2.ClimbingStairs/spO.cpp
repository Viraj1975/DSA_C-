#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b,c;
    a=1;b=1;

    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }

    if(n<2) cout<<n<<endl;
    else cout<<c<<endl;
    return 0;
}