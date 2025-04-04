#include<iostream>
#include<vector>
using namespace std;

// in case of negative numbers ,

// we subtract the minimum number from the array and

// then apply count sort

// and at last add the minimum number to get back our original array.

void count_sort(int array[],int size){
    int max=array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max) max=array[i];
    }
    int freq[max+1]={0};
    for(int i=0;i<size;i++){
        freq[array[i]]++;
    }
    for(int i=1;i<=max;i++){
        freq[i]+=freq[i-1];
    }
    int ans[size];
    for(int i=size-1;i>=0;i--){
        ans[--freq[array[i]]]=array[i];
    }
    for(int i=0;i<size;i++){
        array[i]=ans[i];
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
    count_sort(array,N);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

// we do not apply count sort when there is a huge difference in numbers.

// in case of large numbers and comparatively less size of array its space complexity and time complexity increases.