#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int maximum_subarray(vector<int>arr){ 
     // BY using kadanes algorithm
     int maxi,prefix=0;
      maxi =INT_MIN;
      for(int i=0;i<arr.size();i++){
        prefix += arr[i];
        maxi = max(maxi,prefix);
        if(prefix<0)
        prefix=0;
      }
      return maxi;
}

// to find maximum element of a array
int maximum_element(vector<int>arr){
  int maxi1,store;
  maxi1 = INT_MIN;
  for(int i=0;i<arr.size();i++)
  {
    store=arr[i];
    maxi1 = max(maxi1,store);
  }
  return  maxi1;

}

// to find out maximum element of a array
int minimum_element(vector<int>arr){
  int maxi2,store1;
  maxi2 = INT_MAX;
  for(int i=0;i<arr.size();i++)
  {
    store1=arr[i];
    maxi2 = min(maxi2,store1);
  }
  return  maxi2;

}

int maximum_difference_of_two_elements(vector<int>arr){
  int ans,result;
  ans=INT_MIN;
  for(int i=0;i<arr.size()-1;i++){
    for(int j=i+1;j<arr.size();j++){
      result = arr[j]-arr[i];
      ans =max(ans,result);
    }
  }
   return ans;
}

void two_sum(vector<int>arr ,int target){
  for(int i=0;i<arr.size()-1;i++){
    for(int j=i+1;j<arr.size();j++){
      if(arr[i]+arr[j]==target){
         cout << "target Element is present" << endl;
        return;
      }      
    }
  }
  cout<<"target element is not present\n";
}

void target1(vector<int>arr ,int target){
  for(int i=0;i<arr.size();i++){
    if(arr[i]==target){
      cout<<"target element is present at index no"<<i<<endl;
     return;
    }
  }
  cout<<"target element is not present\n";
}

int divide_equal_subarray_sum(vector<int>arr){
  
  for(int i=0;i<arr.size()-1;i++){
    int sum1=0,sum2=0;
    for(int j=0;j<=i;j++)
    sum1 += arr[j];

     for(int j=i+1;j<arr.size();j++)
      sum2 += arr[j];

    if(sum1==sum2)
    return 1;
  }

  return -1;
}

int peek_index_mountained_array(vector<int>arr){
  int start=0,end=arr.size()-1,mid;
  while(start<=end){
    mid = start + (end-start)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] )
    return mid;

    else if(arr[mid]>arr[mid-1])
    start=mid+1;

    else
     end=mid-1;
  }
  return -1;
}

void sort_array1(vector<int>arr){
  for(int j=0;j<arr.size()-1;j++){
    if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);
  } 

  cout<<"sorted elements are\n";
  for(int j=0;j<arr.size();j++)
  cout<<arr[j]<<" ";
}

void sort_array2(vector<int>arr){
   
}

void selection_sort(vector<int>arr){
  for(int i=0;i<arr.size()-1;i++){
    int index=i;
    for(int j=i+1;j<arr.size();j++){
      if(arr[j]<arr[index])
      index=j;
    }

    swap(arr[i],arr[index]);
  }

   cout<<"sorted elements are\n";
  for(int i=0;i<arr.size();i++)
  cout<<arr[i]<<" ";
}

void smallest_element_index(vector<int>arr){
  int index=0;
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]<arr[index])
    index=i;
  }
  cout<<"smallest element index is :"<<" "<<index<<" "<<"element is :"<<" "<<arr[index];
}

int  largest_product_sum(vector<int>arr){
  int maxi;
  maxi=INT_MIN;
  for(int i=0;i<arr.size()-1;i++)
  {
    int product=0;
     for(int j=i+1;j<arr.size();j++)
     {
          product=arr[i]*arr[j];
          maxi=max(maxi,product);
     }
  }
  return maxi;
}

int  largest_product_sum1(vector<int>arr){
  if(arr.size()<2)
  return 0;
  int start=0,end=arr.size()-1,product;
  int maxi;  
  maxi=INT_MIN;
   while(start<end)
   {
     product=arr[start]*arr[end];
     maxi=max(maxi,product);
     if(arr[start+1]*arr[end]>arr[start]*arr[end-1]) // condition check for next element forbecoming loop part
     start++;
     else
     end--;
   }

   return maxi;
}

void print_subarray(vector<int>arr){
  //for outer loop
  int i,j,k;
  for(int i=0;i<arr.size();i++)
  {
    for(int j=i;j<arr.size();j++)
    {
      cout<<"{";  
      for(int k=i;k<=j;k++)
          {
             cout<<arr[k]<<" ";
          }
            cout<<"}\n";
    }
  }
}




int main()
{
    
    int n,target;
    // vector<int>arr(n);
    cout<<"enter the size of array\n";
    cin>>n;
     vector<int>arr(n);
    cout<<"enter the elements of array\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

   //cout<<maximum_subarray(arr);
   //cout<<maximum_element(arr)<<endl;
   //cout<<minimum_element(arr);

   //cout<< maximum_difference_of_two_elements(arr);

   // cout<<"enter the target element\n";
   //cin>>target;

   //two_sum(arr,target);
   //target1(arr , target);

   //cout<< divide_equal_subarray_sum(arr); 

   //cout<<peek_index_mountained_array(arr);

   //sort_array1(arr);

   //selection_sort(arr);  

  //smallest_element_index(arr);

  // cout<<largest_product_sum1(arr);

  cout << "All subarrays:\n";
   print_subarray(arr);
  
   
    
    
}