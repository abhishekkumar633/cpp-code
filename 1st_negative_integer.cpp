#include<iostream>
#include<queue>
using namespace std;
int display(queue<int>q){
    while(!q.empty())
    {
        if(q.front()<0)
        {
            return q.front();
            q.pop();        
        }     
    }
    return 0;        
}

// Function to find the first negative integer in each sliding window 

queue<int> first_negative_integer(int arr[],int n,int k){
    queue<int>q;
    queue<int>ans;
    for(int i=0;i<k-1;i++)
    q.push(arr[i]);

    for(int i=k-1;i<n;i++)
    {
        q.push(arr[i]);
        ans.push(display(q));
        q.pop();
    }
    return ans;
}
int main()
{
   
    int arr[]={2,-4,3,-5,-6,1,-8};
    int n=7;
    int k=3;
   
   first_negative_integer(arr,n,k);

    

}
