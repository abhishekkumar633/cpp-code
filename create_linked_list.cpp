#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int value)
    {
       data=value;
       next=NULL;
    }
};


Node *create_linked_list(Node *head,int arr[],int n){
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
           
            head=new Node(arr[i]);
        }
        else{
            Node *temp;
            temp=new Node(arr[i]);
            temp->next=head;
            head=temp;
        }
    }

    return head;
}

Node *create_linked_list1(Node *head,int arr[],int n){
    Node *tail;
    head=tail=NULL;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
           
            head=new Node(arr[i]);
            tail=head;

        }
        else{
            Node *temp;
            temp=new Node(arr[i]);
            tail->next=temp;
            tail=temp;
        }
    }

    return head;
}



Node *insert_at_begining(Node *head,int key){
    if(head==NULL)
      Node * head=new Node(key);

    else{
        Node *temp=new Node(key);
        temp->next=head;
        head=temp;
    }
}

Node *insert_at_end(Node *head,int arr[],int n,int key){
    if(head==NULL)
    head=new Node(key);

    else{
        Node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        Node *curr=new Node(key);
        temp->next=curr;
    }

    return head;
}

Node *reverse_LList(Node*head){
    Node* curr=head,*prev=NULL,*front=NULL;
    while(curr!=NULL)
    {
       front=curr->next;
       curr->next=prev;
       prev=curr;
       curr=front; 
    }

    head=prev;
    return head;
}


void print_linked_list(Node *head){
    
  Node *curr=head;
  while(curr!=NULL)
  {
    cout<<curr->data<<" ";
    curr=curr->next;
  }

  cout<<"NULL"<<endl;
}



int main()
{
int key;
Node *head=NULL;
int arr[]={2,4,3,6,7,9};
//  head=create_linked_list(head,arr,6);
//  print_linked_list(head);

  head=create_linked_list1(head,arr,6);
  print_linked_list(head);

 cout<<"enter number to insert at begining\n";
 cin>>key;

  head=insert_at_begining(head,key);
  print_linked_list(head);

   //head=insert_at_end(head,key);
  print_linked_list(head);
}