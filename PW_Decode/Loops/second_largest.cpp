#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l = INT16_MIN;
    int sl = INT16_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>l){
            sl = l;
            l = arr[i];
        }
        if(arr[i]>sl && arr[i]!=l){
            sl = arr[i];
        }
    }
    cout<<l<<" "<<sl;
    return 0;
}