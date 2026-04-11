#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
    
        return mid;
    
               
    else if(arr[mid]<key)
        start=mid+1;
    
    else
         end = mid-1;
    
    
    }  
    return -1; 
}
int main()
{
    int n,key,i;
    int arr[100];
     cout<<"enter the size of array";
     cin>>n;
      cout<<"enter the elements of array";
      for(int i=0;i<n;i++)
      cin>>arr[i];    
    cout<<"enter the key to search";
    cin>>key;

    cout<<binarysearch(arr,n,key);
    return 0;

}
