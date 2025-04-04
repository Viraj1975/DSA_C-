#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void count_sort(vector<int>&v,int pos){
    vector<int>freq(10,0);
    for(int i=0;i<v.size();i++){
        freq[(v[i]/pos)%10]++;
    }

    // cummulative frequency
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    vector<int>ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }
    for(int i=0;i<v.size();i++){
        v[i]=ans[i];
    }
}

void Radix_sort(vector<int>&v){
    int max_ele=INT16_MIN;
    for(int i=0;i<v.size();i++){
        max_ele=max(v[i],max_ele);
    }
    for(int pos=1;max_ele/pos>0;pos*=10){
        count_sort(v,pos);
    }

}

int main(){
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    Radix_sort(v);
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}