#include<iostream>
using namespace std;

int minimum_cost(int heights[],int N,int pos){
    if(pos==N-1) return 0;
    //frog is on first stone
    int first=abs(heights[pos+1]-heights[pos]);
    int second = abs(heights[pos+2]-heights[pos]);
    if(pos==N-2) return first+minimum_cost(heights,N,pos+1);
    return min(minimum_cost(heights,N,pos+1)+first,minimum_cost(heights,N,pos+2)+second);
}

int main(){
    int N;int pos=0;
    cin>>N;
    int heights[N];
    for (int i = 0; i < N; i++){
        cin>>heights[i];
    }
    cout<<minimum_cost(heights,N,pos);
    return 0;
}