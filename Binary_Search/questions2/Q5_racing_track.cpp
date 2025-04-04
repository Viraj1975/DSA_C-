#include<iostream>
using namespace std;

bool can_arrange_students(int array[],int mid,int n,int N){
    int children_reqd = 1;
    int last_placed=array[0];
    for(int i=1;i<N;i++){
        if(array[i]-last_placed>=mid){
            children_reqd++;
            last_placed=array[i];
            if(children_reqd==n) return true;
        }
    }
    return false;
}

int max_of_min_distance(int array[],int N,int n){
        int start=1;
        int end=array[N-1]-array[0];
        int ans=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(can_arrange_students(array,mid,n,N)){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;;
        }
        return ans;
}

int main(){
    int N;
    cout<<"Enter number of starting points : ";
    cin>>N;
    int array[N];
    cout<<"Enter the position of each starting point : ";
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    int n;
    cout<<"Enter number of children : ";
    cin>>n;
    cout<<max_of_min_distance(array,N,n);
    return 0;
}