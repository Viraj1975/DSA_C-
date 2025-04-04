#include<iostream>
using namespace std;

void sort_even_odd(int (&array)[],int size){
    int start=0;
    int end=size-1;
    while(end>start){
        if(array[start]%2!=0 and array[end]%2==0){
            swap(array[start],array[end]);
            start++;
            end--;
        }
        if(array[start]%2==0){
            start++;
        }
        if(array[end]%2!=0){
            end--;
        }
    }
    return;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int array[size];
    for(int i=0 ; i<size ; i++){
        cin>>array[i];
    }
    sort_even_odd(array,size);
    for(int i=0 ; i<size ; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}