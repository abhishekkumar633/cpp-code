#include<iostream>
#include<vector>

using namespace std;
vector<int> reverse(int arr[],int n){
    int n = sizeof(arr) / sizeof(arr[0]);
    int start=0,end=n-1,sum1=0,sum2=0;
    int mid=start +(end-start)/2;
    for(int i=start;i<mid;i++){
        sum1 += arr[start];
    }
      for(int i=mid+1;i<end;i++){
        sum2 += arr[mid+1];
       
    }
    if(sum1 > sum2){
        while(start <= end){
            swap(arr[start],arr[end]);
            start++;
             end--;
        }
    }
    return arr;
}
int main(){
    int arr[]={2,3,4,5,1,2,3};
    cout<<reverse(arr,7);
}