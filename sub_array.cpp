#include<iostream>
#include<vector>
using namespace std;

void subarray(vector<int>&arr){
    int j;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++){        
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
    vector<int>arr={2,1,5,6};
    subarray(arr);
}

