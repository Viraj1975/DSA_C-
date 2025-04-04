#include<iostream>
#include<vector>
using namespace std;

void Bubble_sort(vector<int>&v){
    bool swapped=false;
    for (int i=0;i<v.size()-1;i++){
    bool swapped=false;
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) return;
    }
    return;
}

int main(){
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    Bubble_sort(v);
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}