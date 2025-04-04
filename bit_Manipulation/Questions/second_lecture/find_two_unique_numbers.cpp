#include<iostream>
using namespace std;

int getbit(int value,int pos){
    return ((value & (1<<pos))!=0);
}

void find_two_unique_numbers(int arr[],int size){
    int xorsum = 0;
    for(int i=0;i<size;i++){
        xorsum = xorsum^arr[i];
    }
    int temp = xorsum;
    int pos = 0;
    int setbit = 0;
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    int newxor = 0;
    for(int i=0;i<size;i++){
        if(getbit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(temp^newxor)<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    find_two_unique_numbers(arr,n);
}




