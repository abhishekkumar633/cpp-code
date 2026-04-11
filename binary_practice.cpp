#include<iostream>
using namespace std;
int binary_search(int arr[],int size,int target){
    int start=0,end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==target)
        return mid;

        else if(arr[mid]<target)
          start=mid+1;

          else 
            end=mid-1;       
    }
    return -1;
}

int sum_target(int arr[],int size,int target){
    int start=0,end=size-1;
    while(start<=end)
    {
        if(arr[start]+arr[end]==target)
        return 1;

        else if(arr[start]+arr[end]<target)
          
            start++;

            else
             end--;
        
    }
    return -1;
}
int main()
{
    int target,size;
    cout<<"enter the target element\n";
    cin>>target;
    int arr[]={2,4,5,7,9,10};
    size=sizeof(arr)/sizeof(arr[0]);
    //cout<<binary_search(arr, size,target);
    // if (result != -1)
    //     cout << "Element found at index: " << result << endl;
    // else
    //     cout << "Element not found" << endl;

    cout<<sum_target(arr,size,target);
    
}