#include<iostream>
#include<limits.h>
using namespace std;
int second_element1(int arr[],int n){
    int ans=INT_MIN;
    for(int i=0;i<6;i++)
    {
        if(arr[i]>ans)
        {
            ans=arr[i];
        }
    }

    int second_element=INT_MIN;
    for(int i=0;i<6;i++)
    {
        if(arr[i]!=ans)
        {
            second_element=max(second_element,arr[i]);
        }
    }
    return second_element;
}
int main(){
    int arr[]={12,23,45,13,78,98};
   //int result second_element1(arr,5);
    int result = second_element1(arr, 5);

    if (result == INT_MIN) {
        cout << "No second largest element found" << endl;
    } else {
        cout << "The second largest element is: " << result << endl;
    }
    //return 0;
  
}

