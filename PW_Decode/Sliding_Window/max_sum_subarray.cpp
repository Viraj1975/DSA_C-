#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int>v,int k){
    int max_sum=INT16_MIN;
    int ct = 0;
    int sum = 0;
    int max_idx = -1;
    for(int i=0;i<v.size();i++){
        if(i<k){
            sum+=v[i];
        }
        else{
            sum+=v[i]-v[i-k];
            if(sum>max_sum){
                max_sum = sum;
                max_idx = i-k+1;
            }
        }
    }
    cout<<max_idx<<" ";
    return max_sum;
}

int main(){
    vector<int>v = {7,1,2,5,8,4,9,3,6};
    int k;
    cin>>k;
    cout<<max_sum(v,k);
    return 0;
}