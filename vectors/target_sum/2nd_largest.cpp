#include<iostream>
using namespace std;

int main(){
    int array[] = {2,3,5,7,6,1};
    int size = sizeof(array)/sizeof(array[0]);
    int max=INT8_MIN,second_max=INT8_MIN;
    for(int i=0 ; i<size ; i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    for(int i=0 ; i<size ; i++){
        if(array[i]>second_max && array[i]!=max){
            second_max=array[i];
        }
    }
    cout<<second_max;  
    return 0;
}