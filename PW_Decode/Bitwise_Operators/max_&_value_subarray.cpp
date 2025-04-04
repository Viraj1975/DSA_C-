#include<bits/stdc++.h>
using namespace std;

int max_and_value_subarray(vector<int>v){
    int mx = v[0];
    int idx = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>mx){
            mx = v[i];
            idx = i;
        }
    }

    int i = idx;
    int j = idx+1;
    while(j<v.size() && v[j]==v[i]){
        j++;
    }
    cout<<i<<" "<<j-1<<endl;
    return j-i;
}

int main(){
    vector<int>v = {12,3,1,6,1,6,6,6,4,3,8,13,13,13,8};
    cout<<max_and_value_subarray(v);
    return 0;
}