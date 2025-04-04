#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int top;
    int *arr;
    unsigned capacity;
};

struct stack* create_stack(unsigned size){
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->capacity=size;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

void push(struct stack* stack,int value){
    if(stack->top==stack->capacity-1){
        return;
    }
    stack->top=stack->top+1;
    stack->arr[stack->top]=value;
}

int pop(struct stack* stack){
    if(stack->top==-1){
        return INT_MIN;
    }
    int curr = stack->arr[stack->top];
    stack->top=stack->top-1;
    return curr;
}

int is_empty(struct stack* stack){
    return (stack->top==-1);
}

int is_full(struct stack* stack){
    return (stack->top==stack->capacity-1);
}

int get_top(struct stack* stack){
    return (stack->arr[stack->top]);
}

void display(struct stack* stack){
    while(stack->top!=-1){
        printf("%d ",stack->arr[stack->top]);
        stack->top=stack->top-1;
    }
}

int main(){
    struct stack* stack = create_stack(10);
    for(int i=0;i<10;i++){
        push(stack,i);
    }
    display(stack);
    return 0;
}