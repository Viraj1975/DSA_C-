#include<iostream>
using namespace std;

int peak_element(int array[],int size){
    int start = 0;
    int end = size-1;
    int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(array[mid]>array[mid-1]){
            ans=max(ans,mid);
            start=mid+1;
        } 
        else end = mid - 1;
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    cout<<peak_element(array,N);

    return 0;
}