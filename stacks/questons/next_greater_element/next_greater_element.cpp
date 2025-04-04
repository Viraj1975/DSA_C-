#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> next_greater_element(vector<int>&arr){
    stack<int>st;
    int size = arr.size();
    vector<int>result(size,-1);
    st.push(0);
    for(int i=1;i<size;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            result[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(not st.empty()){
        result[st.top()]=-1;
        st.pop();
    }
    return result;
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
    vector<int>arr1 = next_greater_element(arr);
    for (int i=0;i<size;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}