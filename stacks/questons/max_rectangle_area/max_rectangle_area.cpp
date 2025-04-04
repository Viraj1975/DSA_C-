#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int max_rectangle_area(vector<int>&arr){
    stack<int>st;
    int size = arr.size();
    int ans = INT16_MIN;
    st.push(0);
    for(int i=1;i<size;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            int ele = arr[st.top()];
            st.pop();
            int nsi = i;
            int psi = (st.empty()) ? (-1) : st.top();
            ans = max(ans,ele*(nsi-psi-1));
        }
        st.push(i);
    }
    while(not st.empty()){
        int ele = arr[st.top()];
        int nsi = size;
        st.pop();
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max(ans,ele*(nsi-psi-1));
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the values : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<max_rectangle_area(arr);
    return 0;
}