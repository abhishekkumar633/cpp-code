#include<iostream>
using namespace std;
class LLNode
{
    public:
    int data;
    LLNode *next;

    LLNode(int value)
    {
       data=value;
       next=NULL;
    }
};

LLNode *create_linked_list1(LLNode *head,int arr[],int n){
    LLNode *tail;
    head=tail=NULL;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
           
            head=new LLNode(arr[i]);
            tail=head;

        }
        else{
            LLNode *temp;
            temp=new LLNode(arr[i]);
            tail->next=temp;
            tail=temp;
        }
    }

    return head;
}

LLNode* seperate_duplicate_element(LLNode* head){
  LLNode *prev,*curr;
  if (head == NULL || head->next == NULL) {
        return head; // No duplicates in an empty or single-node list
    }
    prev=head;
    curr=head->next;
    while(curr!=NULL)
    {
        if(curr->data==prev->data)
        {
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else{
            prev=prev->next;
            curr=curr->next;
        }
    }
 return head; 
}  
bool is_palindrome(LLNode* head){
    LLNode* curr=head;
    int count=0;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    count=count/2;
    LLNode *prev;
    curr=head;
    prev=NULL;
    while(count--)
    {
        prev=curr;
        curr=curr->next;
    }

    // Now reverse the second half part of LList
    LLNode *front=NULL;
     curr=head,*prev=NULL;
    while(curr!=NULL)
    {
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }

    // Now do comprasion 
    LLNode* head1=head,*head2=prev;
    while(head1)
    {
        if(head1->data != head2->data)
        return 0;

        else{
            head1=head1->next;
            head2=head2->next;
        }
    }
  return 1;   
}

void print_linked_list(LLNode *head){
    
  LLNode *curr=head;
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
LLNode *head=NULL;
int arr[]={1,2,3,3,2,1};
//  head=create_linked_list(head,arr,6);
//  print_linked_list(head);

  head=create_linked_list1(head,arr,6);
 print_linked_list(head);

 head=seperate_duplicate_element(head);
  print_linked_list(head);

  //cout<<"total node are : "<<total_no_of_nodes(head);


  cout<<is_palindrome(head);
   
}
