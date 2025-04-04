#include<iostream>
#include<string>
using namespace std;


int main(){
    string str [] = {"00123","00980","345","543","0140"};
    int maxVal = stoi(str[0]);
    string maxStr;
    for(string x: str){
        int val = stoi(x);
        if(val>maxVal){
            maxVal = val;
            maxStr = x;
        }
    }
    cout<<maxStr<<" "<<maxVal<<endl;

    return 0;
}