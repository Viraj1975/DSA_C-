#include<iostream>
using namespace std;

int main(){
    int array[] = {2,4,5,5,5,4,2,5,6,8,3,8,9,5,3};
    int size = sizeof(array)/sizeof(array[0]);
    int unique_number;
    for(int i=0 ; i<size ; i++){
        if(array[i]==-1) continue;
        for(int j=i+1 ; j<size;j++){
            if(array[i]==array[j]){
                array[i]=-1;
                array[j]=-1;
            }
        }
    }
    for(int i=0 ; i<size ; i++){
        if(array[i]!=-1){
            unique_number=array[i];
            break;
        }
    }
    cout<<unique_number;
    return 0;
}