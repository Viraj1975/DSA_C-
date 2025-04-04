#include<iostream>
using namespace std;

bool can_distribute_chocolate(int array[],int mid,int n,int N){
    int students_reqd = 1;
    int current_sum=0;
    for(int i=0;i<N;i++){
        if(array[i]>mid) return false;
        if(current_sum+array[i]>mid){
            students_reqd++;
            current_sum=array[i];
            if(students_reqd>n) return false;
        }
        else current_sum+=array[i];
    }
    return true;
}

int min_of_max_chocolates_distributed(int array[],int N,int n){
        int start=array[0];
        int sum=0;
        for (int i=0;i<N;i++){
            sum+=array[i];
        }
        
        int end=sum;
        int ans=-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(can_distribute_chocolate(array,mid,n,N)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
}

int main(){
    int N;
    cout<<"Enter number of boxes : ";
    cin>>N;
    int array[N];
    cout<<"Enter number of chocolate in each box : ";
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    cout<<min_of_max_chocolates_distributed(array,N,n);
    return 0;
}