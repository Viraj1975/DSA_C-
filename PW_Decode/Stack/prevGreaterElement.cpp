#include<bits/stdc++.h>
using namespace std;

vector<int> prevGreaterElementArray(vector<int>v){
    vector<int>ans(v.size(),-1);
    stack<int>st;
    st.push(v[0]);
    for(int i=1;i<v.size();i++){
        while(st.size()>0 && st.top()<=v[i]) st.pop();
        if(st.size()!=0) ans[i]=st.top();
        st.push(v[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++){
        int ele;
        cin>>ele;
        v[i]=ele;
    }
    vector<int>ans = prevGreaterElementArray(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}