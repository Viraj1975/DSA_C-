#include<iostream>
using namespace std;

void insertion_sort(int array[],int size){
    for(int step=1;step<size;step++){
        int key=array[step];
        int j=step-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
    return;
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    insertion_sort(array,N);
    for (int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    
    return 0;
}