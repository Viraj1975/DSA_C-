#include<iostream>
using namespace std;

int main(){
    int size,count_element,k=0;
    cin>>size;
    int array[size];int array1[size]={0};
    for(int i=0;i<size ; i++){
        cin>>array[i];
    }
    for(int i=0;i<size-1;i++){
        count_element=1;
        for(int j=i+1,p=0 ; j<size,p<k ; j++,p++){
            if(array[i]==array[j] && array[i]!=array1[p]){
                array1[k++]=array[i];
            }
        }
    }
    cout<<"Repeated elements are : ";
    for(int i=0 ; i<k ; i++){
        cout<<array1[i]<<" ";
    }
    return 0;
}