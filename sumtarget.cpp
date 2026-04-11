#include<iostream>
using namespace std;
int pairtarget_sum(int arr[],int n,int target){
    int ans;
    for(int i=0;i<n-1;i++){
        ans=target-arr[i];
       int start = i+1,end=n-1;
       while(start<end){
        if(arr[start]+arr[end]==ans){
             return 1;
        }
       
        else if(arr[start]+arr[end]>ans){
             end--;
        }
       
        else
             start++;
       }
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
    cout<<pairtarget_sum(arr,n,target);
    if (pairtarget_sum(arr, n, target))
        cout << "Pair with target sum exists.\n";
    else
        cout << "No pair with target sum exists.\n";

    return 0;

}

