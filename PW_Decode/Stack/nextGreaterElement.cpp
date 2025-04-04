#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementArray(vector<int>v){
    // SC = O(n);
    // TC = O(n);
    int n = v.size();
    vector<int>ans(n,-1);
    stack<int>st;
    ans[n-1]=-1;
    st.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && v[i]>=st.top()) st.pop();
        if(st.size()!=0) ans[i]=st.top();
        st.push(v[i]); 
    }
    return ans;
}

int main(){
    vector<int>v(8);
    for(int i=0;i<8;i++){
        int ele;
        cin>>ele;
        v[i]=ele;
    }
    vector<int>ans = nextGreaterElementArray(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}