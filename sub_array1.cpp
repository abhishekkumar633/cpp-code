#include<iostream>
using namespace std;
void sub_array(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
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
    int arr[]={2,3,4};
    sub_array(arr,3);
}

