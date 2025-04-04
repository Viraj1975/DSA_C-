#include<iostream>
using namespace std;

void recursive_Bubble_sort(int array[],int size){
    if(size==1) return;
    int count=0;
    for(int i=0;i<size-1;i++){
        if(array[i]>array[i+1]){
            swap(array[i],array[i+1]);
            count++;
        }
    }
    if(count==0) return;
    recursive_Bubble_sort(array,size-1);
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    recursive_Bubble_sort(array,N);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}