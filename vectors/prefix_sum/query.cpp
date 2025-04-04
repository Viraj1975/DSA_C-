#include<iostream>
#include<vector>
using namespace std;

void query_range_sum(vector<int>&v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    int q,l,r,result;
    cin>>q;
    while(q--){
        cin>>l;cin>>r;
        if(l>1){
        result=v[r-1]-v[l-1];
        }
        else{
            result=v[r-1];
        }
        cout<<result;
    }

    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    query_range_sum(v);
    return 0;
    // or we can make a vector of size n+1 and initialise all elements with zero.
}