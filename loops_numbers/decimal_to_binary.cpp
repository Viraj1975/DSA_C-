#include <iostream>
using namespace std;

int main(){
    // rem == parity digit
    int decimal_number,rem,binary_number=0,power=1;
    cout<<"Enter the number in decimal form : ";
    cin>>decimal_number;
    while(decimal_number>0){
        rem = decimal_number%2;
        binary_number += rem*power;
        power*=10;
        decimal_number/=2;
    }
    cout<<binary_number;
    return 0;
}