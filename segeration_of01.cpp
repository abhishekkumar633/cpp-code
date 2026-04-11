#include<iostream>
using namespace std;
void segeration_of0and1(int arr[],int n){
    int count0 = 0,count1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
         count0++;
         else
          count1++; 
    }
    for (int i=0;i<count0;i++)
    arr[i]=0;
     for (int i=count0;i<n;i++)
    arr[i]=1;
}

void segerate(int arr[],int n){
    int start=0,end=n-1;
    while(start<end){
        if(arr[start]==0)       
        start++;
        else{
            if(arr[end]==0){
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
            else
              end--;
        }
    }

     //cout<<"segerated array is :";
     printf("segerated array is :\n");
    for(int i=0;i<n;i++)
   // cout<<arr[i]<<" ";
   printf("%d",arr[i]);

}
int main()                                                                  
{
    int n;
    int arr[100];
    // cout<<"enter the size of array\n";
    // cin>>n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    //cout<<"enter the elements\n";
     printf("elements of a array\n");
    for(int i=0;i<n;i++)
    //cin>>arr[i];
     scanf("%d",&arr[i]);
   //segeration_of0and1(arr,n);

    //print the segerated array 

    // cout<<"segerated array is :";
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";

    segerate(arr, n);

    return 0;
}