#include<iostream>
#include<vector>
using namespace std;


// void print_max(int arr[],int i,int max){
//     if(i==-1){
//         cout<<max;
//         return;
//     }
//     if(max<arr[i]) max=arr[i];
//     print_max(arr,i-1,max);
// }

int maxInArray(int arr[],int i){
    if(i==-1) return INT16_MIN;
    return max(arr[i],maxInArray(arr,i-1));
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // print_max(arr,n-1,INT16_MIN);
    cout<<maxInArray(arr,n-1);
    return 0;
}