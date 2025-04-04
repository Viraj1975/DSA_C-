#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r2 = (p2.first*1.0)/(p2.second*1.0);
    return r1 > r2;
}

int fractionalKnapsack(vector<int>&profit,vector<int>&weight,int n,int w){
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        arr.push_back({profit[i],weight[i]});
    }
    sort(arr.begin(),arr.end(),comp);

    int pft = 0;
    for(int i=0;i<n;i++){
        if(arr[i].second<=w){
            pft+=arr[i].first;
            w-=arr[i].second;
        }
        else{
            pft+=((arr[i].first*1.0)/(arr[i].second*1.0))*w;
            w=0;
            break;
        }
    }
    return pft;
}

int main(){
    return 0;
}