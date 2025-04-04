#include<iostream>
#include<vector>
using namespace std;

// void print_ele(vector<int>v,int i){
//     if(i==v.size()) return;
//     cout<<v[i]<<" ";
//     print_ele(v,i+1);
// }

void print_ele2(int arr[],int n){
    if(n==-1) return;
    print_ele2(arr,n-1);
    cout<<arr[n]<<" ";
}

int main(){
    int n;cin>>n;
    // vector<int>v(n);
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // print_ele(v,0);
    print_ele2(arr,n-1);
    return 0;
}