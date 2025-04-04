#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

void bucket_sort(vector<float>&v){
    int n=v.size();
    vector<vector<float>>bucket(n,vector<float>());

    // inserting elements
    for(int i=0;i<n;i++){
        int ele=floor(v[i]*n);
        bucket[ele].push_back(v[i]);
    }
    
    // sorting individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // combining individual buckets
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            v[k++]=bucket[i][j];
        }
    }
}

int main(){
    int N;
    cin>>N;
    vector<float>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    bucket_sort(v);
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}