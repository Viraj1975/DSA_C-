#include<iostream>
using namespace std;

void merge_array(int array[],int array1[],int array2[],int size1,int size2){
    int i=0; // pointer for first array i.e array1 .
    int j=0; // pointer for second array i.e array2 .
    int k=0; // pointer for resultant array i.e array .
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
    return ;
}

int main(){
    int size1,size2;
    cin>>size1;
    int array1[size1];
    for(int i=0;i<size1;i++){
        cin>>array1[i];
    }
    cin>>size2;
    int array2[size2];
    for(int i=0;i<size2;i++){
        cin>>array2[i];
    }
    int array[size1+size2]={0};
    merge_array(array,array1,array2,size1,size2);
    for(int i=0;i<size1+size2;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}