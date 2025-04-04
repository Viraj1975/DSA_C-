#include<iostream>
#include<vector>
using namespace std;

void sum_of_all_subsets(int array[],int size,int idx,int sum,vector<int>&result){
    if(idx==size){
        result.push_back(sum);
        return;
    }
    sum_of_all_subsets(array,size,idx+1,sum+array[idx],result);
    sum_of_all_subsets(array,size,idx+1,sum,result);
}

int main(){
    int N;cout<<"Enter the size of array : ";
    cin>>N;int idx=0,sum=0;vector<int>result;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];+
    }
    sum_of_all_subsets(array,N,idx,sum,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}