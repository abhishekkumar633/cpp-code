#include<iostream>
using namespace std;
void reverse_array(int arr[],int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
}
int search_element(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        return i;
    }
    return -1;

}
int main()
{
    int n,target,i;
    int arr[100];
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    reverse_array(arr,n);
    cout<<"reversed array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // for searching from a given array!!!

    cout<<"enter the target ekement\n";
    cin>>target;
   int result= search_element(arr,n,target); 
   if(result!=-1){
    cout<<"elemnts are present at index"<<result<<" ";
   }   
        else{
            cout<<"elemnts are not presnt\n";
        }
    return 0;
}