#include<iostream>
#include<limits.h>
using namespace std;
int maxdiff_b2elements(int arr[],int n){
  int ans=INT_MIN;
  for(int i=0;i<n-1;i++) // This loop is used for dividing array into diffrent subarray
  {
    for(int j=i+1;j<n;j++)                 
    ans=max(ans,arr[j]-arr[i]);
  }
  return ans;
}
int main()           
{
    int n;
     int arr[100];
     cout<<"enter the size of array";
     cin>>n;
      cout<<"enter the elements of array";
      for(int i=0;i<n;i++)
      cin>>arr[i]; 
      cout<<maxdiff_b2elements(arr,n);
}