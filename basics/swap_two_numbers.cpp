#include<iostream>
using namespace std;

int main(){
    int first_no,second_no;
    cout<<"Enter first number : ";
    cin>>first_no;
    cout<<"Enter second number : ";
    cin>>second_no;
    int t=first_no;
    first_no=second_no;
    second_no=t;
    cout<<"first_no : "<<first_no<<endl;
    cout<<"second_no : "<<second_no;
    return 0;
}