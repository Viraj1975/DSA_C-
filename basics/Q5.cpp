#include<iostream>
#include<climits>
using namespace std;

int Find_secondLowest(int array[],int N){
    int min=INT16_MAX;int secondmin=INT16_MAX;int idx=0;
    for(int i=0;i<N;i++){
        if(array[i]<=min and array[i]!=INT16_MIN){
            min=array[i];idx=i;
        }
    }
    array[idx]=INT16_MAX;
    for(int i=0;i<N;i++){
        if(array[i]<secondmin && array[i]!=INT16_MIN) secondmin=array[i];
    }
    return secondmin;
}

int Find_secondHighest(int array[],int N){
    int max=INT16_MIN;int secondmax=INT16_MIN;int idx=0;
    for(int i=0;i<N;i++){
        if(array[i]>=max){
            max=array[i];
            idx=i;
        }
    }
    array[idx]=INT16_MIN;
    for(int i=0;i<N;i++){
        if(array[i]>secondmax) secondmax=array[i];
    }
    return secondmax;
}

int main(){
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    cout<<"Second Highest element is "<<Find_secondHighest(array,N)<<endl;
    cout<<"second lowest element is "<<Find_secondLowest(array,N);
    return 0;
}