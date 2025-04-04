#include<iostream>
#include<vector>
using namespace std;

// we can also find index of the element just greater than target element .
// this is callwd calculating upper bound .
void last_occurence(vector<int>&v,int ans[],int x){
    int start=0;
    int end=v.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(v[mid]<=x){
            start=mid+1;
            if(v[mid]==x) ans[1]=mid;
        }
        else{
            end=mid-1;
        }
    }
}

void first_occurence(vector<int>&v,int ans[],int x){
    int start=0;
    int end=v.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(v[mid]>=x){
            end=mid-1;
            if(v[mid]==x) ans[0]=mid;
        }
        else{
            start=mid+1;
        }
    }
}

int main(){
    int N;
    cin>>N;
    vector<int>v;
    for(int i=0;i<N;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int x;cin>>x;
    int ans[]={-1,-1};
    first_occurence(v,ans,x);
    if(ans[0]!=-1) last_occurence(v,ans,x);
    if(ans[1]==-1) ans[1]=ans[0];
    cout<<ans[0]<<" "<<ans[1];
}