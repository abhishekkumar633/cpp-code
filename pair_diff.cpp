#include<iostream>
using namespace std;
bool pair_diff(int arr[],int n,int target){
    int start=0,end=1;
    while(start<end){
        if(arr[end]-arr[start]==target)
        return 1;
        else if(arr[end]-arr[start]<target)
        end++;
        else
        start++;
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
    cout<<pair_diff(arr,n,target);
}