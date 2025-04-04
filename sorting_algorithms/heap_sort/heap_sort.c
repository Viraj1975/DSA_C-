#include<stdio.h>

void max_heapify(int arr[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r; 
    }
    if(largest!=i){
        int t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        max_heapify(arr,n,largest);
    }
    return;
}

void heap_sort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int t = arr[i];
        arr[i] = arr[0];
        arr[0] = t;
        max_heapify(arr,i,0);
    }
    return;
}

int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heap_sort(arr,n);
    printf("the elements of array after sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}