#include<iostream>
using namespace std;

bool check_Palindrome(int num,int *temp){
    if(num>=0 && num<10){
        int lastdigit0f_temp=(*temp)%10;
        (*temp)/=10;
        return (num==lastdigit0f_temp);
    }     
    bool result=(check_Palindrome(num/10,temp) and (num%10)==((*temp)%10));
    (*temp)/=10;
    return result;
}

int main(){
    int num;
    cin>>num;
    int temp=num;
    cout<<check_Palindrome(num,&temp);
    return 0;
}