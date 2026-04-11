#include<iostream>
#include<vector>
using namespace std;
int sum_of_unique_element(int arr[],int n){
    vector<int>freq(7,0);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<freq.size();i++)
    {
        if(freq[i]==1)
        sum += i;
    }

    return sum;
}

bool three_sum(int arr[],int n,int target){
    for(int i=0;i<n-2;i++)
    {
        int ans = target-arr[i];
    int start=i+1,end=n-1;
    while(start<=end)
    {
        if(arr[start]+arr[end] == ans)
        {
            return 1;
        }

        else if(arr[start]+arr[end] < ans)
        {
           start++;
        }
        else{
            end--;
        }
    }
}
return 0;
}

int main()
{
   // int arr[]={1,2,3,2,4,5,3,6};
    int arr[]={1,4,4,5,6,10,5};
    //cout<<sum_of_unique_element(arr,8);
    cout<<three_sum(arr,7,13);
}