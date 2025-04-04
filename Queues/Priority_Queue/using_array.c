#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct item{
    int data;
    int priority;
};

int size = -1;
struct item queue[1000];

void enqueue(int key,int priority){
    size++;
    queue[size].data=key;
    queue[size].priority=priority;
    return;
}

int highest_priority_index(){
    int index = -1;
    int highest_priority = INT_MIN;
    for(int i=0;i<=size;i++){
        if(highest_priority==queue[i].priority && index>-1 && queue[i].data>queue[index].data){
            highest_priority=queue[i].priority;
            index=i;
        }
        else if(highest_priority<queue[i].priority){
            highest_priority=queue[i].priority;
            index=i;
        }
    }
    return index;
}

int dequeue(){
    int index = highest_priority_index();
    if(index==-1){
        printf("Queue is empty");
        return INT_MAX;
    }
    int current = queue[index].data; 
    for(int i=index;i<size;i++){
        queue[i]=queue[i+1];
    }
    size--;
    return current;
}

int main(){
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
 
    int ind1 = highest_priority_index();
    printf("%d\n",queue[ind1].data);
    dequeue();

    int ind2 = highest_priority_index();
    printf("%d\n",queue[ind2].data);
    dequeue();
 
    int ind3 = highest_priority_index();
    printf("%d\n",queue[ind3].data);
  
    return 0;
}