#include<iostream>
using namespace std;

void recursive_selection_sort(int array[],int size,int index){
    if(index==size-1) return;
    int i=index;
    for(int j=index+1;j<size;j++){
        if(array[j]<array[i]){
            i=j;
        }
    }
    if(i!=index){
        swap(array[i],array[index]);
    }
    recursive_selection_sort(array,size,index+1);
}

int main(){
    int N;int index=0;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    recursive_selection_sort(array,N,index);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}