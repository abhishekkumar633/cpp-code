#include<iostream>
using namespace std;

// To check it is a palindrome or not..

int main()
{
    string s1="Radha";
    int start=0,end = s1.size()-1;
    while(start<end){
        if(s1[start]!=s1[end])
        {  
            cout<<"it is not a palindrome";
            return 0;
        }

        start++ ;
        end--;
    }
 cout<<"it is a palindrome";

// To reverse a string

 string s2="Naresh";
    int start=0 ,end=s2.size()-1;
    while(start<end){
        swap(s2[start],s2[end]);
        start++;
        end--;
    }
cout<<s2;

// To calculate size of a string    
}



