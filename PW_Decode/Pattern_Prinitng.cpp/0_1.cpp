#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = 0;
    for(int i=1;i<=n;i++){
        a = (i%2==0)?0:1;
        for(int j=1;j<=i;j++){
            // if((i+j)%2==0){
            //     cout<<"1 ";
            // }else{
            //     cout<<"0 ";
            // }

            // second approach
            cout<<a<<" ";
            if(a==0) a=1;
            else a=0;
        }
        cout<<endl;
    }
    return 0;
}