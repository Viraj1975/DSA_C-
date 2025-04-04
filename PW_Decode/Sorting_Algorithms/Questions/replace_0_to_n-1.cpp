#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v = {5,8,9,3,10};
    vector<int>visited(5,0);

    int val = 0;
    for(int i=0;i<5;i++){
        int smallest = INT16_MAX;
        int idx = -1;
        for(int j=0;j<5;j++){
            if(visited[j]==0 && v[j]<smallest){
                smallest = v[j];
                idx = j;
            }
        }
        v[idx] = val++;
        visited[idx] = 1;
    }

    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}