#include<stdio.h>
#include<stdlib.h>
typedef struct dLList{
    int data;
    struct dLList* next;
    struct dLList* prev;   
}Node;

Node* create_node(int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
}

Node* create_dLList(Node* head,int arr[],int n)
{
     head=NULL;
    Node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        Node* newnode=create_node(arr[i]);
        if(head==NULL)
        {
            head =newnode;
            tail=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=NULL;
            tail=newnode;
        }
    }
 return head;
}

Node* insert_at_begning(Node* head){
    int x=100;
    Node* temp=head;
    Node* newnode=create_node(x);
    newnode->next=temp;
    newnode->prev=NULL;
    temp->prev=newnode;
    head=newnode;

    return head;
}

Node* insert_at_last(Node* head){
    int x=200;
    Node* back=NULL,*curr=head;
   while(curr->next!=NULL)
   {
    back=curr;
    curr=curr->next;
   }
   Node* newnode=create_node(x);
   newnode->prev=back->next;
   curr->next=newnode;
   newnode->next=NULL;

   return head;
}



void print_LList(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    Node* head=NULL;
    int arr[]={2,3,1,5,67,8};

    head=create_dLList(head,arr,6);
    print_LList(head);

    head=insert_at_begning(head);
    print_LList(head);

    head=insert_at_last(head);
    print_LList(head);
  

}