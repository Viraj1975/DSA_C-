#include<iostream>
#include<queue>
using namespace std;

void Minimum_cost(int arr[],int size){
    int cost = 0;
    priority_queue<int>q;
    for(int i=0;i<size;i++)
        q.push(arr[i]);

    while(q.size()>1){
        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        int sum = a+b;
        cost+=sum;
        q.push(sum);
    }

}

int main(){
    return 0;
}

