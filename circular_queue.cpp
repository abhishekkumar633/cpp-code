#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class queue
{
    int *arr;
    int front,rear;
    int size;
    public:
    queue(int n)
    {
        arr=new int[n]; // for user input element storation
        front=rear=-1;
        size=n;
    }

    bool is_empty(){
        return front==-1;     
    }

    bool is_full(){
        return (rear+1)%size==front;
    }

    void push(int x){
        if(is_empty())
        {
            front=rear=0;
            arr[0]=x;           
        }
        else if(is_full()){
           cout<<"queue is overflow\n";
            return;
        }
       else{
        rear=(rear+1)%size;
        arr[rear]=x;
       }
    }

    void pop()
    {
        if(is_empty())
        {
           cout << "Queue is empty (underflow)\n";
        }
        else{
            if(front==rear)
            front=rear=-1;

            else
                front=(front+1)%size;
        }
    }

   void display() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
int main()
{
   queue<int>q(5);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.display();

    q.pop();
    q.pop();
    q.display();

    q.push(60);
    q.push(70);
    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();

    return 0;
}