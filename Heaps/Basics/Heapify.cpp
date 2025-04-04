#include<iostream>
using namespace std;

void Heapify(int arr[],int index,int size){
    int largest = index;
    int LC_index = 2*index+1;
    int RC_index = 2*index+2;

    if(LC_index<size && arr[largest]<arr[LC_index]){
        largest = LC_index;
    }
    if(RC_index<size && arr[largest]<arr[RC_index]){
        largest = RC_index;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        Heapify(arr,largest,size);
    }
    return;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=(size/2)-1;i>=0;i--){
        Heapify(arr,i,size);
    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}