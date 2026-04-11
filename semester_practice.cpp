#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool check_parenthsis(string str){
    stack<char>st; // for storing char into stack
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        st.push(str[i]);

        else
            {
                if(st.empty())              
                    return 0;
               else
                    st.pop();
            }
    }

    return st.empty();
}

bool check_parenthesis1(string str){
    stack<char>st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            st.push(str[i]);
            else if(st.empty())
                 return 0;

            else if(str[i]==')'){
                if(st.top()!='(')
                return 0;
                else    
                    st.pop();
            }
               
             else if(str[i]=='}'){
                if(st.top()!='{')
                return 0;
                else    
                    st.pop();
            }

            else
                {
                    if(st.top()!=']')
                return 0;
                else    
                    st.pop();
                }       
    }

    return st.empty();
}

// insert next grater element  in a new  array of a given array!!

vector<int> next_greater_element(int arr[],int n){
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            ans[i]=arr[j];
            break;
        }
    }

    return ans;

}

// implementation of linear queue

class queue
{
    int *arr;
    int front;
    int rear;
    int size;

    public:
        queue(int value)
        {
            front=-1;
            rear=-1;
            size=value;
        }

        bool is_empty()
        {
            return front==-1;
        }
        bool is_fulll()
        {
            return rear==size-1;
        }

        void push(int x){
            if(is_empty())
            {
                front=rear=0;
                arr[front]=x;
            }
                else
                    {
                        if(is_fulll())
                        cout<<"queue is overlow\n";
                    }
        }

        void pop(){
            if(is_empty())
             cout<<"queue is underflow\n";
             else 
                {
                    front=front+1;
                }
        }

        int peek_element(){
             if(is_empty())
             cout<<"queue is underflow\n";

             else
                return arr[front];
        }
};
 
 // implementation of circular queue

 class queue
 {
    int *arr;
    int front;
    int rear;
    int size;

    queue(int value)
    {
        front=-1;
        rear=-1;
        size=value;
        arr = new int(value);
    }

    bool is_empty()
    {
            return front==-1;
    }

    bool is_full(){
        return rear==(size-1)%size;
    }

    int push(int x)
    {
         if(is_empty())
            {
                front=rear=0;
                arr[front]=x;
            }
                else
                    {
                        if(is_full())
                        cout<<"queue is overlow\n";
                    }
    }
 };

 

int main()
{
    int arr[]={8,6,4,7,4,9,10,8,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    // string str;  
    // cout<<"enter string to check parentehsis\n";
    // getline(cin,str);
    // cout<< check_parenthsis(str)<<endl;


    //  cout<<"enter string to check parentehsis\n";
    // getline(cin,str);
    // cout<< check_parenthesis1(str);


    // Call the function
    vector<int> result = next_greater_element(arr, n);

    // Print the result
    cout << "Next greater elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;




}