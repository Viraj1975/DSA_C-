#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a=0;
    vector<int>v(6);
    for(int i=0 ; i<6 ; i++){
        cin>>v[i];
    }
    for(int i=0 ; i<6 ; i++){
        cout<<v[i]<<" ";
    }

    for(int i=1 ; i<5 ; i++){
        if(v[i]>=v[i-1] && v[i]<=v[i+1]){
            a=1;
        }
        else{
            a=0;
            break;
        }
    }
    cout<<endl;
    if(a==1) cout<<"Sorted.";
    else cout<<"Not Sorted.";

    return 0;
}