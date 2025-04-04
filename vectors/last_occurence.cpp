#include<iostream>
#include<vector>
using namespace std;

int main(){
    int element,occurrence=-1,count=0,greater=0;
    vector<int>v(6);
    for(int i=0 ; i<6 ; i++){
        cin>>v[i];
    }
    cout<<"Enter the element to be found : ";cin>>element;
    for(int i=0 ; i<6 ; i++){
        cout<<v[i]<<endl;
    }

    for(int i=0 ; i<6 ; i++){
        if(v[i]==element){
            occurrence=i;
            count++;
        }
        if(v[i]>element){
            greater++;
        }
    }
    cout<<occurrence<<endl;
    cout<<count<<endl;
    cout<<greater<<endl;

    return 0;
}