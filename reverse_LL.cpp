#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int value)
    {
        data=value;` 
        next=NULL;
    }
};

Node* create_LList(Node* head,int arr[],int n){
    Node *tail=NULL;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head=new Node(arr[i]);
            tail=head;
        }
        else{
            Node* temp=new Node(arr[i]);
            tail->next=temp;
            tail=temp;
        }
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

void print_LList(Node* head){
    Node* curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;

}
int main()
{
    Node* head=NULL;
    int arr[]={4,2,7,5,39,1};
    // head=create_LList(head,arr,6);
    // print_LList(head);


    // head=reverse_LList(head);
    // print_LList(head);

    int choice;
    do
    {
        /* code */
        cout<<"menu driven\n";
        cout<<"create_LList\n";
        cout<<"reverse_LList\n";
        cout<<"display\n";
        cout<<"exit\n";
        cout<<"enter choice\n";
        cin>>choice;
    switch(choice)
    {
        case 1:
                 head=create_LList(head,arr,6); 
                 break;
                  //print_LList(head);

        case 2:
                 head=reverse_LList(head);
                 break;
                // print_LList(head);

        case 3:
                print_LList(head);
                break;
        case 4:
                cout<<"exit\n";
                return 0;
        
        default:
                cout<<"wrong choice entered\n";       

    }
        
        

    } while(choice!=3);
}