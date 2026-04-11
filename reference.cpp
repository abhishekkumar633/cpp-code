#include<iostream>
#include<vector>
using namespace std;
void swapping(int &first,int &second)  // pass by reference 
{
    int temp=first;
        first =second;
        second=temp;
    cout<<first<<endl;
    cout<<second<<endl;
}

void  change_value(vector<int>&v) // pass by reference u can also use temp variable instead of while passing through refernce

{
    for(int i=0;i<5;i++)
    v[i]=10;

    // for final printing the value
    for(int i=0;i<5;i++)
    cout<<v[i]<<" ";

}

void dob(int arr[5]){
    for(int i=0;i<5;i++)
    arr[i]=2*arr[i];

    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int first=10,second=20;
    swapping(first,second);

    vector<int>v(5,0);
    change_value(v);

    int arr[5]={1,2,3,4,5};
    dob(arr);
  
}