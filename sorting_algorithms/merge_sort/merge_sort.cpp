#include<iostream>
using namespace std;

void merge(int array[],int start,int mid,int end){
    int size1=mid-start+1;
    int size2=end-mid;
    // create two temporary array;
    int array1[size1];int array2[size2];
    for(int i=0;i<size1;i++){
        array1[i]=array[start+i];
    }
    for(int j=0;j<size2;j++){
        array2[j]=array[mid+1+j];
    }
    int i=0;// initial index of first subarray array1;
    int j=0;// initial index of second subarray array2;
    int k=start;
    while(i<size1 && j<size2){
        if(array1[i]>array2[j]) array[k++]=array2[j++];
        else array[k++]=array1[i++];
    }
    while(i<size1){
        array[k++]=array1[i++];
    }
    while(j<size2){
        array[k++]=array2[j++];
    }
}

void Merge_sort(int array[],int start,int end){
    int mid = start + (end-start)/2;
    // Base case
    if(start>=end){
        return;
    }
    Merge_sort(array,start,mid);
    Merge_sort(array,mid+1,end);
    merge(array,start,mid,end);
    return;
}

int main(){
    int N;int start=0;
    cin>>N;int end=N-1;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    Merge_sort(array,start,end);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;    
}