#include<bits/stdc++.h>
using namespace std;

int partition(int array[],int start,int end){
    int pivot = array[start];
    int i = start-1;
    int j = end+1;

    while(true){
        do{
            i++;
        }while(array[i]<pivot);

        do{
            j--; 
        }while(array[j]>pivot);

        if(i>=j) return j;
        swap(array[i],array[j]);
    }
}

int partition_r(int array[],int start,int end){
    int random = start + rand()%(end-start);
    swap(array[random],array[start]);
    return partition(array,start,end);
}

void Quick_sort(int array[],int start,int end){
    if(start>=end){
        return;
    }
    int i=partition_r(array,start,end);
    Quick_sort(array,start,i);
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

