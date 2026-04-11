#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int value){
        data=value;
        next=NULL;
    }

};
int main()
{
    int arr[]={2,5,3,8,5,9};
    int i;
    Node *head;


  for(int i=0;i<6;i++){
    if(head == NULL){
        head = new Node(arr[i]);       
    }

    else{
        Node *temp;
        temp = new Node(arr[i]);
        temp->next=head;
        head=temp;

    }
  }

 Node *temp;
  temp=head;

 while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }

 
  // Delete 1st node

//   Node *temp;
//   temp=head;
  head=head->next;
  delete temp;

 // for printing the data;

  



}