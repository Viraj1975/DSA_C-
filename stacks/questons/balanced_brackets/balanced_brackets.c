#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct stackNode{
    char data;
    struct stackNode* next;
};

struct stackNode* create_node(char data){
    struct stackNode* new_node = (struct stackNode*)malloc(sizeof(struct stackNode));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(struct stackNode** head,char value){
    struct stackNode* new_node = create_node(value);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    new_node->next=(*head);
    (*head)=new_node;
    return;
}

char pop(struct stackNode** head){
    if(!(*head)){
        return 'E';
    }
    struct stackNode* temp = *head;
    *head = temp->next;
    char curr = temp->data;
    free(temp);
    return curr;
}

char peak(struct stackNode* head){
    if(!head) return 'E';
    return head->data;
}

int is_empty(struct stackNode* head){
    if(!head) return 1;
    return 0;
}

void display(struct stackNode* head){
    struct stackNode* temp = head;
    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->next;
    }   
}

int check_validity(char str[]){
    int i = 0;
    struct stackNode* temp = NULL;
    while(str[i]!='\0'){
        if(str[i] == ']' || str[i] == '}' || str[i] == ')'){
            if(is_empty(temp)){
                return 0;
            }
            else{
                if(str[i]==']' && temp->data=='['){
                    pop(&temp);
                }
                else if(str[i]==')' && temp->data=='('){
                    pop(&temp);
                }
                else if(str[i]=='}' && temp->data=='{'){
                    pop(&temp);
                }
                else{
                    return 0;
                }
            }
        }
        else{
            push(&temp,str[i]);
        }
        i++;
    }
    if(is_empty(temp)) return 1;
    else return 0;
}

int main(){
    struct stackNode* head = NULL;
    char* string = NULL;
    size_t buf_size = 32;
    string = (char*)malloc(buf_size*sizeof(char));
    if(string==NULL){
        perror("Memory Allocation failed .");
        exit(1);
    }
    printf("Enter the string : ");
    getline(&string,&buf_size,stdin);
    string[strcspn(string,"\n")] = '\0';
    int result = check_validity(string);
    printf("%d",result);
    free(string);
    return 0;
}