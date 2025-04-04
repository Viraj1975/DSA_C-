#include<iostream>
using namespace std;

int main(){
    int size,count_element;
    cin>>size;
    int array[size];
    for(int i=0;i<size ; i++){
        cin>>array[i];
    }
    for(int i=0;i<size;i++){
        count_element=1;
        for(int j=i+1 ; j<=size;j++){
            if(array[i]==array[j] && array[j]!=-1){
                count_element++;
                array[j]=-1;
            }
        }
        if(array[i]!=-1){
        cout<<"Element : "<<array[i]<<" "<<"occurence : "<<count_element<<endl;
        }
    }
    return 0;
}