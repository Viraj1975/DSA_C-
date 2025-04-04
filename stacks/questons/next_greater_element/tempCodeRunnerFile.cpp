#include<iostream>
#include<stack>
using namespace std;

int* next_greater_element_array(int arr[],int size){
    stack<int>st;
    int result[size] = {-1};
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
    int arr[size];
    cout<<"Enter the values : ";
    for(int i=0;i<size;i++){
        int ele;
        cin>>ele;
    }
    int arr1[size] = next_greater_element_array(arr,size);
    for (int i=0;i<size;i++){
        cout<<arr1[i]<<" ";
    }
    
    return 0;
}