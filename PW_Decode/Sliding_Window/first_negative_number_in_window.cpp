#include<bits/stdc++.h>
using namespace std;

vector<int> find_ans_vector(vector<int>v,int k){
    int length = 1;
    int n = v.size();
    vector<int>ans;
    int p = -1;
    for(int i=0;i<k;i++){
        if(v[i]<0){
            p = i;
            break;
        }
    }
    if(p==-1) ans.push_back(1);
    else ans.push_back(v[p]);
    int i = p;
    int j = p+k-1;
    while(j<n){
        if(p>=i) ans.push_back(v[p]);
        else{
            p = -1;
            for(int t=i;t<=j;t++){
                if(v[t]<0){
                    p = t;
                    break;
                }
            }
            if(p==-1) ans.push_back(1);
            else ans.push_back(v[p]);
        }
        i++;j++;
    }
    return ans;

    // TC : O(n);
}

int main(){
    vector<int>v = {2,-3,4,4,-7,-1,4,-2,6};
    int k;
    cin>>k;
    vector<int>ans = find_ans_vector(v,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}