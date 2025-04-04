#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int idx = 0;
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            swap(v[idx],v[i]);
            idx++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}