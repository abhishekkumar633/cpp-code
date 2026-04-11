#include<iostream>
using namespace std;
int main()
{
    int arr[5]={2,4,3,5,3};
    int *ptr=arr;
    // To print the value of a corrresponding array
    // for(int i=0;i<5;i++){
    //     cout<<*(arr+i)<<endl;
    //     cout<<arr[i]<<endl;   
    // }

     // To print the address of a corrresponding array
    //for(int i=0;i<5;i++){
        //cout<<(arr+i)<<endl;
       // cout<<arr[i]<<endl;   
   // }

for(int i=0;i<5;i++)
{
  //  cout<<ptr[i]<<" ";
    cout<<*(ptr+i)<<" ";

}

cout<<*(ptr+3);

    return 0;
}