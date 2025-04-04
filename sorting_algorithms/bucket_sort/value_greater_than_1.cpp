#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

void bucket_sort(vector<float>&v){
    int n=v.size();
    vector<vector<float>>bucket(n,vector<float>());

    // finding minimum element and maximum element;
    float min_ele=v[0];
    float max_ele=v[0];
    for(int i=0;i<n;i++){
        min_ele=min(v[i],min_ele);
        max_ele=max(v[i],max_ele);
    }

    // calculating range
    float range=(max_ele-min_ele)/n;

    // inserting elements;
    for(int i=0;i<n;i++){
        int index=floor((v[i]-min_ele)/range);
        float diff=(v[i]-min_ele)/range - index;
        if(diff==0 && v[i]!=min_ele) bucket[index-1].push_back(v[i]);
        else bucket[index].push_back(v[i]);
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