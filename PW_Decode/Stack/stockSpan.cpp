#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpanArray(vector<int>v){
    int n = v.size();

    vector<int>pgi(n,-1);
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && v[st.top()]<=v[i]) st.pop();
        if(st.size()!=0) pgi[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        pgi[i]=i-pgi[i];
    }
    return pgi;
}

int main(){
    vector<int>v(8);
    for(int i=0;i<v.size();i++){
        int ele;
        cin>>ele;
        v[i]=ele;
    }
    vector<int>ans = stockSpanArray(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}