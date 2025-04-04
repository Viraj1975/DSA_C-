#include<iostream>
using namespace std;

int medianofThree(int array[],int start,int end){
    int mid = start + (end-start)/2;
    if(array[start]>array[mid]) swap(array[start],array[mid]);
    if(array[start]>array[end]) swap(array[start],array[end]);
    if(array[mid]>array[end]) swap(array[mid],array[end]);

    return mid;
}

int partition(int array[],int start,int end){
    int pivotIndex = medianofThree(array,start,end);
    int pivot = array[pivotIndex];

    swap(array[pivotIndex],array[end]);

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