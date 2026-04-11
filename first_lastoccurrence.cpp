#include<iostream>
using namespace std;
int firstoccurrence(int arr[],int n,int target)
{
    int start=0,end=n-1,first=-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==target)
        {
              first=mid;
              end=mid-1;
        }
        else if(arr[mid]<target)
            start=mid+1;
        else
            end=mid-1;  
    }
    return first;
}
int lastoccurrence(int arr[],int n,int target)
{
    int start=0,end=n-1,last=-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==target)
        {
              last=mid;
              start=mid+1;
        }
        else if(arr[mid]<target)
            start=mid+1;
        else
            end=mid-1;  
    }
    return last;
}
int main()
{
    int n,target;
    int arr[100];
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements of array\n";
    for(int i=0;i<n;i++)
     cin>>arr[i];
    cout<<"enter the target element";
    cin>>target;
    int firstresult=firstoccurrence(arr,n,target); //function call
    if(firstresult!=-1)
    {
        cout<<"first element :"<<target<<"is at index" <<firstresult<<endl;       
    }
     else{
         cout << "The target element " << target << " was not found in the array." << endl;
     }
      int lastresult=lastoccurrence(arr,n,target); //function call
    if(lastresult!=-1)
    {
        cout<<"last element :"<<target<<"is at index" <<lastresult<<endl;       
    }
     else{
         cout << "The target element " << target << " was not found in the array." << endl;
     }
    return 0;
}

