#include<iostream>
using namespace std;

// int target_X(int array[],int size,int idx,int X){
//     if(idx==size) return 0;
//     if(array[idx]==X) return 1;
//     return target_X(array,size,idx+1,X);
// }

bool target_X(int array[],int size,int idx,int X){
    if(idx==size) return false;
    return (array[idx]==X) || target_X(array,size,idx+1,X);
}

int main(){
    int size,X,idx=0;cout<<"Enter the size of array : ";
    cin>>size;
    int array[size];
    cout<<"Enter the elements of array : ";
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter the target value X : ";cin>>X;
    int result = target_X(array,size,idx,X);
    if(result) cout<<"Yes";
    else cout<<"No";
    return 0;
}