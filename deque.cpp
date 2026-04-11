#include<iostream>
using namespace std;

// implementation of deque using array
class deque
{
    int front,rear,size;
    int *arr;
    public:

    deque(int n)
    {
        arr=new int[n]; // n size of array has been created
        front=rear=-1;
        size=n;
    }

    bool is_empty(){
       return  front==-1;
    }

    bool is_full(){
      return ( rear+1)%size==front;
    }

    void push_back(int x){
        if(is_full())
        {
            cout<<"overflow\n";
            return;
        }
        else if(is_empty())
        {
            front=rear=0;
            arr[0]=x;
            return;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }

     void push_front(int x){
        if(is_full())
        {
            cout<<"overflow\n";
            return;
        }
        else if(is_empty())
        {
            front=rear=0;
            arr[0]=x;
            return;
        }
        else{
            front=(front-1+size)%size;
            arr[front]=x;
        }
    }

    void pop_back(){
        if(is_empty())
        {
            cout<<"underflow\n";
            return;
        }
        else if(front==rear)
        {
            front=rear=-1;
            return;
        }
        else{
            rear=(rear-1+size)%size;
        }
    }


     void pop_front(){
        if(is_empty())
        {
            cout<<"underflow\n";
            return;
        }
        else if(front==rear)
        {
            front=rear=-1;
            return;
        }
        else{
            front=(front+1+size)%size;
        }
    }

    int peek_element(){
         if(is_empty())
         {
            cout<<"underflow\n";
            return -1;           
         }
         return arr[front];
    }


     int end_element(){
         if(is_empty())
         {
            cout<<"underflow\n";
            return -1;           
         }
         return arr[rear];
    }

    void display(){
        if(is_empty())
        {
            cout<<"underflow\n";
            return;            
        }

        else if((rear+1)%size==front)
        {
            cout<<"no more eleemnt is allowed to insert\n";
            return;
        }
    else{
        cout<<"deque element\n";
        int i=front;
        while(true){
            cout<<arr[i]<<" ";
            if(i==rear)
            break;
            i=(i+1)%size;
        }
        cout<<endl;
    }
    }
};

int main()
{
     int choice,size,value;
     deque dq(size);
     cout<<"enter the size of deque\n";
     cin>>size;
    do
    {
        /* code */
        
        cout<<"menu driven\n";
        cout<<"enter 1 to push_back element\n";
        cout<<"enter 2 to push_front element\n";
        cout<<"enter 3 to pop_back element\n";
        cout<<"enter 4 to pop_front element\n";
        cout<<"enter 5 to see peek element\n";
        cout<<"enter 6 to see end elemen\n";
        cout<<"enter 7 to dispaly\n";
        cout<<"enter 8 to exit\n";
        cout<<"enter your choice\n";
        cin>>choice;
    switch(choice)
    {
        case 1:
                cout<<"enter the value of element to push back";
                cin>>value;
                dq.push_back(value);
                break;
        case 2:              
                 cout<<"enter the value of element to push front";
                cin>>value;
                dq.push_front(value);
                break;

        case 3:
                dq.pop_back();
                break;

        case 4:                 
                dq.pop_front();
                break;

        case 5:
                cout<<"peek element is :"<<dq.peek_element()<<endl;
                break;
        case 6:
                cout<<"end element is :"<<dq.end_element()<<endl;
                break;

        case 7:
                dq.display();
                break;
        case 8:
                cout << "Exiting program.\n";
                return 0;

        default:
                cout << "Invalid choice, try again.\n";        
    }



    } while (choice!=8);
   
}
