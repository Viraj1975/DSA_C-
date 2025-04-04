#include<bits/stdc++.h>
using namespace std;

void pip(int n){
    if(n==0) return;
    cout<<n<<" ";
    pip(n-1);
    cout<<n<<" ";
    pip(n-1);
    cout<<n<<" ";
}

int main(){
    int row;
    cin>>row;
    for(int i=1;i<=row;i++){
        pip(i);
        cout<<endl;
    }
    return 0;
}