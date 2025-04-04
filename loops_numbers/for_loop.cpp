#include<iostream>
using namespace std;

int main(){
    // for(init-statement ; condition ; final-expression){
    //      code;
    // }
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cout<<i<<endl;
    }
    // we can also omit parts of loops but dont forget to include semicolon.
    // we can also use two variables in a loop.

    // break -> pure loop se bahar aa jaayega.
    // continue -> sirf wahi iteration skip ho jayega baki loop chalta rahega.
    return 0;
}