#include<iostream>
#include<vector>
using namespace std;

// will work only for unique elements

void subArray(vector<int>arr,int idx,vector<int>temp,vector<vector<int>>&ans){
    if(idx==arr.size()){
        ans.push_back(temp);
        return;
    }
    subArray(arr,idx+1,temp,ans);
    if(temp.empty() || temp[temp.size()-1]==arr[idx-1]){
        temp.push_back(arr[idx]);
        subArray(arr,idx+1,temp,ans);
    }
}

int main(){
    vector<int>arr={1,2,3,4};
    vector<int>temp;
    vector<vector<int>>ans;
    int n = 4;
    subArray(arr,0,temp,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}