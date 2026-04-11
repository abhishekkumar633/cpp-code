#include<iostream>
#include<algorithm>
using namespace std;
int partition(int arr[],int start,int end){
    int pos=start;
    for(int i=start;i<=end;i++)
    {
        if(arr[i]<=arr[end])
        {
            swap(arr[i],arr[pos]);
            pos++;
        }
    }

return pos-1;
}
void quick_sort(int arr[],int start,int end){

    if(start>=end)
    return;
    int pivot=partition(arr,start,end);
    //left array part
    quick_sort(arr,start,pivot-1);

    //right array part

     quick_sort(arr,pivot,end);

    

    
    
} 
int main()
{
    int arr[]={4,2,6,8,3,9,10};
    quick_sort(arr,0,6);

     cout<<"sorted array are :";
    for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";

     
    
}
