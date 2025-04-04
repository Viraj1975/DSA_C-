#include<iostream>
using namespace std;

// worst case time complexity : O(N^2)
// average case time complexity : O(N);

int partition(int array[],int start,int end){
    int pivot=array[end];
    int i=start;
    for(int j=start;j<end;j++){
        if(array[j]<pivot){
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[i],array[end]);
    return i;
}

int kth_smallest_element(int array[],int start,int end,int k){
    if(k>=0 && k<end-start+1){
        int i = partition(array,start,end);

        if(i-start==k-1) return array[i];
        else if(i-start>k-1){
            return kth_smallest_element(array,start,i-1,k);
        }
        else{ 
            return kth_smallest_element(array,i+1,end,k-start+i-1);
        }
    }
    return INT16_MAX; 
}

int main(){
    int N;int k;
    cin>>N;
    int start=0;int end=N-1;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    cin>>k;
    cout<<kth_smallest_element(array,start,end,k);
    return 0;
}