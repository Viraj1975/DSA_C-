#include<bits/stdc++.h>
using namespace std;

int findMedian(int array[],int n){
    sort(array,array+n);
    return array[n/2];
}

int medianOfMedians(int array[],int start,int end){
    int n = end-start+1;
    if(n<=5){
        return findMedian(array+start,n); 
    }

    int numMedians = (n+4)/5;
    int medians[numMedians];

    for(int i=0;i<numMedians;i++){
        int groupLow = start+i*5;
        int groupHigh = min(groupLow+4,end);
        medians[i] = findMedian(array+groupLow,groupHigh-groupLow+1);
    }

    return medianOfMedians(medians,0,numMedians-1);
}

int partition(int array[],int start,int end,int pivot){
    for(int i=start;i<end;i++){
        if(array[i]==pivot){
            swap(array[i],array[end]);
            break;
        }
    }
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
    int pivot = medianOfMedians(array,start,end);
    int i=partition(array,start,end,pivot);
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