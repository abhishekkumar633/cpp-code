#include<stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top=NULL;
void push(int x){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=NULL;
    top=newnode;
}

void pop(){
    Node* temp=top;
    if(top==0)
    printf("stack is empty\n");
    else{
        top=top->next;
        free(temp);
    }
}

        