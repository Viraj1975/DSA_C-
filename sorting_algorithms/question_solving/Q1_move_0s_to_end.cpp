#include<iostream>
using namespace std;

// void swap_Zeros(int array[],int size){
//     for(int i=0;i<size-1;i++){
//         bool swapped=false;
//         for(int j=0;j<size-i-1;j++){
//             if(array[j+1]!=0 && array[j]==0){
//                     swap(array[j],array[j+1]);
//                     swapped=true;
//             }
//         }
//         if(!swapped) return;
//     }
//     return ;
// }

void swap_Zeros(int array[],int size){
    for(int i=size-1;i>=0;i--){
        int j=0;
        bool swapped=false;
        while(j!=i){
            if(array[j]==0 && array[j+1]!=0){
                swap(array[j],array[j+1]);
                swapped=true;
            }
            j++;
        }
        if(!swapped) return;
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
    swap_Zeros(array,N);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}