#include<iostream>
using namespace std;

// To sort a given array by using heap sort;

void Heapify(int arr[],int index,int n){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest])
    largest=left;

    if(right<n && arr[right]>arr[largest])
    largest=right;

    if(largest != index)
    {
        swap(arr[largest],arr[index]);
        Heapify(arr,largest,n);        
    }   
}

void Build_Max_Heap(int arr[],int n){
    for(int i=(n/2-1);i>=0;i--)
    {
        Heapify(arr,i,n);
    }
}

void sort_array(int arr[],int n){
    for(int i=n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
       
    }
     cout<<endl;
}

int main()
{
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    Build_Max_Heap(arr,10);
    sort_array(arr,10);
    print_array(arr,10);
   

}