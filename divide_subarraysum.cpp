
  // To divide array in such a way that their sum of  two subarray becomes equal by using kadanes algorithm

#include<iostream>
using namespace std;
bool divide_subarraysum(int arr[],int n){
    int prefix=0,Total_sum=0,ans;

    for(int i=0;i<n;i++) // calculated total sum of a given array
    Total_sum+=arr[i];

    for(int i=0;i<n-1;i++){
        prefix=prefix+arr[i];
       ans=Total_sum-prefix;
        if(ans == prefix)
        return 1;
    }
    return 0;

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
    cout<<divide_subarraysum(arr,n)<<"";

}