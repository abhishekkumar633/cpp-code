#include<iostream>
using namespace std;
bool pair_sum(int arr[],int n,int target){
    int start=0,end=n-1;
    while(start<end){
        if(arr[start]+arr[end]==target)
        return 1;
            else if(arr[start]+arr[end]<target)
            start++;
                else
                  end--;
    }
    return 0;
}
int main()
{
    int n,target;
    int arr[100];
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the target element\n";
    cin>>target;
    cout<<pair_sum(arr,n,target);
}