#include<iostream>
using namespace std;

void max_selection_sort(int array[],int size){
    for(int i=size-1;i>0;i--){
        int index=i;
        for(int j=i;j>=0;j--){
            if(array[j]>array[index]){
                index=j;
            }
        }
    if(index!=i) swap(array[i],array[index]);
    }
    return ;
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    max_selection_sort(array,N);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}