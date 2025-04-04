#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front;
    int rear;
    int *arr;
    unsigned capacity;
};

struct Queue* create_queue(unsigned capacity){
    struct Queue* Queue = (struct Queue*)malloc(sizeof(struct Queue));
    Queue->front=-1;
    Queue->rear=-1;
    Queue->capacity=capacity;
    Queue->arr=(int *)malloc(capacity*sizeof(int));
    return Queue;
}

int is_empty(struct Queue* Queue){
    if(Queue->rear==-1) return 1;
    return 0;
}

int is_full(struct Queue* Queue){
    if(Queue->rear==Queue->capacity-1){
        return 1;
    }
    return 0;
}

void Enqueue(struct Queue* Queue,int data){
    if(is_full(Queue)){
        printf("Overflow");
        return;
    }
    Queue->rear = Queue->rear + 1;
    Queue->arr[Queue->rear] = data;
    return;
}

int Dequeue(struct Queue* Queue){
    if(is_empty(Queue)){
        printf("Underflow");
        return INT_MIN;
    }
    int curr = Queue->arr[Queue->front];
    Queue->front = Queue->front + 1;
    return curr;
}

int front(struct Queue* Queue){
    if(is_empty(Queue)){
        printf("front element does not exist.");
        return INT_MIN;
    }
    return Queue->arr[Queue->front];
}

void display(struct Queue* Queue){
    int start = Queue->front;
    int end = Queue->rear;
    for(int i=start;i<=end;i++){
        printf("%d ",Queue->arr[i]);
    }printf("\n");
    return;
}

int main(){
    struct Queue* Queue = create_queue(5);
    for(int i=0;i<5;i++){
        Enqueue(Queue,i);
    }
    display(Queue);
    Dequeue(Queue);
    display(Queue);
    Dequeue(Queue);
    Dequeue(Queue);
    Dequeue(Queue);
    Dequeue(Queue);
    display(Queue);
    Enqueue(Queue,10);
    display(Queue);
    free(Queue);
    return 0;
}