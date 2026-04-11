#include<iostream>
using namespace std; 
void pointer(int *p){
    *p=*p+5;
   cout<<*p<<endl;
}

int main()
{
    int first=10;
    int *ptr= &first;
    pointer(ptr);
  //  cout<<first<<endl; 
   // cout<<ptr<<endl;
}