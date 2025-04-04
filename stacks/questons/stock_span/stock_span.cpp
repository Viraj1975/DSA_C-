#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> stock_span(vector<int>& V){
    stack<int>st;
    int n = V.size();
    reverse(V.begin(),V.end());
    vector<int>result(n,-1);
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && V[i]>V[st.top()]){
            result[st.top()]=n-i-1;
            st.pop();
        }
        st.push(i);
    }
    while(not st.empty()){
        result[st.top()]=-1;
        st.pop();
    }
    reverse(result.begin(),result.end());
    reverse(V.begin(),V.end());
    return result;
}

int main(){
    int size;
    cin>>size;
    vector<int>V(size);
    for(int i=0;i<size;i++){
        cin>>V[i];
    }
    vector<int>result = stock_span(V);
    for(int i=0;i<result.size();i++){
        cout<<i-result[i]<<" ";
    }
    return 0;
}