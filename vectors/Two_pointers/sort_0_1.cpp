#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &v){
    int end=v.size()-1;
    int start=0;
    while(end>start){
        if(v[start]==1 && v[end]==0){
            v[start++]=0;
            v[end--]=1;
        }
        if(v[start]==0){
            start++;
        }
        if(v[end]==1){
            end--;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0 ; i<n ; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    sort(v);
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}




















