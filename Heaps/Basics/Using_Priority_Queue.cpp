#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Max Heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<pq.top()<<"\n";
    cout<<pq.size()<<"\n""\n";


    // Min Heap
    priority_queue<int,vector<int>,greater<int>>MH;
    MH.push(4);
    MH.push(2);
    MH.push(5);
    MH.push(3);

    cout<<MH.top()<<"\n";
    cout<<MH.size();
    return 0;
}