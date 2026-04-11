#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}Node;  

int count_elements(Node *head){
    int count=0;
    Node* curr=head;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
        
    }
    return count;
}

Node* create_node(int value){
   Node*  newnode=(Node*)malloc(sizeof(Node));
   newnode->data=value;
   newnode->next=NULL;
   return newnode;
}

Node* create_list(Node* head,int arr[],int n){
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
            tail=newnode;
        }
    }
 return head;
}

Node* insert_at_first(Node* head,int x){
    printf("enter the value to insert\n");
    scanf("%d",&x);
     Node* newnode=create_node(x);
     newnode->next=head;
     head=newnode;

     return head;
}

Node* insert_at_last(Node* head,int x){
     printf("enter the value to insert\n");
    scanf("%d",&x);
    Node* curr=head; 
   
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    Node* newnode=create_node(x);
    curr->next=newnode;

    return head;

}

Node* insert_at_position(Node* head,int pos,int x){
     printf("enter the value to insert\n");
    scanf("%d",&x);

     printf("enter the position insert\n");
    scanf("%d",&pos);
    Node* curr=head;
    while(pos--)
    {
        curr=curr->next;
    }
   Node* newnode=create_node(x);
   newnode->next=curr->next;
   curr->next=newnode;

   return head;

}

int check_palindrome(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++; 
        temp=temp->next;                   
    }

    count=count/2;
    Node* curr=head;
   
    while(count--)
    {
        curr=curr->next;
    }

    // now reverse half part of the llinkedlist;

    Node* prev=NULL,*front=NULL;
    while(curr)
    {
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }

    // now do comparision b/w two llinkedlist
    Node* head1=head, *head2=prev;
    while(head2)
    {
        if(head1->data != head2->data)
        return 0;

        else
        {
            head1=head1->next;
            head2=head2->next;
        }
    }

    return 1;
}

Node* delete_nth_node_from_end(Node *head,int end){

     int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;                   
    }
     if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
   
    Node* prev=NULL,*curr=head,*front=NULL;
     count=count-end;
    while(count--)
    {
        curr=curr->next;
        prev=curr;
        
    }
     prev->next=curr->next;
    free(curr);
   

    return head;

}

Node* rotate_list_by_twoposition(Node* head,int k){
     int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;                   
    }
    Node* curr=head,*prev=NULL;
    count=count-k;
    while(count--)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    Node* tail=head;
    while(tail!=NULL)
    {
        tail=tail->next;
    }
    
    tail->next=head;
    head=curr;

    return head;
}

Node* delete_at_begning(Node* head){
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
    return head;
}

Node* delete_at_last_position(Node* head){
    Node* prev=NULL,*curr=head;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);

    return head;
}

Node* delete_at_certain_posotion(Node* head){
    int pos;
    int count=count_elements(head);
    printf("enter the position\n");
    scanf("%d",&pos);
    Node* prev=NULL,*curr=head;
    // if(pos>count || pos<count)
    // printf("enter right position\n");
    
    
         while(pos--)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);

   

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

// typedef struct LList
// {
//     int data;
//     struct LList *next;
// }Node;

// Node*  create_node(int value)
// {
//     Node* newnode=(Node*)malloc(sizeof(Node));
//     Node* newnode=(Node*)malloc(sizeof(Node));
//     newnode->data=value;
//     newnode->next=NULL;

//     return newnode;
// }


int main()
{
    int x,pos;

    Node *head=NULL;
    int arr[]={1,2,3,3,2,1};
    
    head=create_list(head,arr,6);
     print_LList(head);

     //head=insert_at_first(head,x);
      //print_LList(head);

      //head=insert_at_last(head,x);
      //print_LList(head);

    //    insert_at_position(head,pos, x);
    //    print_LList(head);

    //  if (check_palindrome(head)) {
    //     printf("The linked list is a palindrome.\n");
    // } else {
    //     printf("The linked list is not a palindrome.\n");
    // }
    // int end=2;
    // head=delete_nth_node_from_end(head,end);
    // print_LList(head);
    //int k=2;

    // head=rotate_list_by_twoposition(head,k);
    //  print_LList(head);

    head=delete_at_begning(head);
     print_LList(head);

     head=delete_at_last_position(head);
      print_LList(head);

      head= delete_at_certain_posotion(head);
       print_LList(head);

     int count=count_elements(head);
     printf("no of elements in LList is%d",count);
     return 0;

}
