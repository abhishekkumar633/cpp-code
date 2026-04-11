#include<iostream>
using namespace std;
int main()
{
     int arr[]={2,3,4,5,6,7,7};
     int total_vowel=0;
     int sum=0;
     for(int i=0;i<7;i++)
     {
        sum += arr[i];
    }

     cout<<"sum is :"<<" "<<sum;

    char arr[]={"abhishekkumar"};
    for(int i=0;i<'\0';i++)
    {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            total_vowel += arr[i];
           
        }
       
    }

      cout<<total_vowel; 
}