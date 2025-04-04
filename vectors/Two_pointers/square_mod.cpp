#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mode_sort(vector<int>&v){
    vector<int>ans;
    int start=0;
    int end=v.size()-1;
    while(start<=end){
        if(abs(v[start])>abs(v[end])){
            ans.push_back(v[start]*v[start]);
            start++;
        }
        else{
            ans.push_back(v[end]*v[end]);
            end--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return;

}

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0 ; i<n ; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    mode_sort(v);
    return 0;
}