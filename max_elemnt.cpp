#include<iostream>
#include<limits.h>
using namespace std;
int max_element(int arr[],int n)
{
    int ans= INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>ans)
        ans=arr[i];
    }
    return ans;

}
int main()
{
    int n;
    int arr[100];
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"max element is"<< max_element(arr,n)<<endl;
    return 0;
}