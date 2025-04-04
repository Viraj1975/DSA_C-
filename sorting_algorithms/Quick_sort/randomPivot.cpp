#include<iostream>
using namespace std;

int partition(int array[],int start,int end){
    int pivotIndex = start + rand()%(end-start+1);
    swap(array[pivotIndex],array[end]);
    int pivot = array[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(array[j]<pivot){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[end]);
    return (i+1);       
}

void Quick_sort(int array[],int start,int end){
    if(start>=end){
        return;
    }
    int i=partition(array,start,end);
    Quick_sort(array,start,i-1);
    Quick_sort(array,i+1,end);
    return;
}

int main(){
    int N;int start=0;
    cin>>N;int end=N-1;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    Quick_sort(array,start,end);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;    
}