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

void Build_Heap(int arr[],int size){
    for(int i=size/2-1;i>0;i--){
        Heapify(arr,0,size);
    }
}

void Heap_sort(int arr[],int size){
    Build_Heap(arr,size);
    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
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
    Heap_sort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}