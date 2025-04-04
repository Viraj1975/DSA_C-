#include<iostream>
using namespace std;

void Selection_sort(int array[],int size){
    for(int i=0;i<size-1;i++){
        int idx=i;
        for(int j=i+1;j<size;j++){
            if(array[j]<array[idx]){
                idx=j;
            }
        }
        if(idx!=i){
            swap(array[i],array[idx]);
        }
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
    Selection_sort(array,N);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
}