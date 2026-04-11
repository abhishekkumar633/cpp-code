#include<iostream>
#include<vector>
using namespace std;
void countoccurrence(int arr[],int n){
    //vector<int>temp(n,0);
    int max_avl=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_avl)
        {
            max_avl=arr[i];
        }
    }

    vector<int>count(max_avl+1,0);
   
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=0;i<=max_avl+1;i++)
    {
        //cout<<"frequency of" + i <<count[i]<<endl;
        cout << "Frequency of " << i << " : " << count[i] << endl;
    }
}
int main()
{
    int arr[]={2,1,4,2,0,1,2,6};
    countoccurrence(arr,8);
}