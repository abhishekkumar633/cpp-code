#include<iostream>
#include<limits.h>
using namespace std;

// best approach:-> To add array in such a way that their sum of subarray becomes maximum??

 int kadane_algorithm(int arr[],int n){
    int maxi,prefix=0;
    maxi=INT_MIN;
    for(int i=0;i<n;i++){
        prefix += arr[i];
        maxi=max(prefix,maxi);
        if(prefix<0)
        prefix=0;
    }
    return maxi;
 }

 // second approach

 int sumof_subarray(int arr[],int n){
    int maxi;
    maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int prefix=0;
        for(int j=i;j<n;j++){
            prefix += arr[j];
            maxi=max(prefix,maxi);
        }
    }
    return maxi;

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
    //cout<<kadane_algorithm(arr,n);
    cout<<sumof_subarray(arr,n);
}