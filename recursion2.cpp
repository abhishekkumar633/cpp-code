#include<iostream>
using namespace std;
int fact(int n){

    if(n==1) // base condition
    return 1;   

   // return n*fact(n-1);
}

int sum_of_natural_number(int n){

     if(n==1) // base condition
    return 1;

    return n+(sum_of_natural_number(n-1));
}



int square_sum(int n){

    if(n==1) // base condition
    return 1;

   return  n*n + square_sum(n-1);
}

int cube_sum(int n){

    if(n==1) // base condition
    return 1;

   return  n*n*n + square_sum(n-1);
}
int main()

{
    int n;
   // cout<<"enter the no whom u want to get factorial\n";
    //cin>>n;
    //cout<<fact(n);

     cout<<"enter the no to get sum of n natural number\n";
     cin>>n;

   // cout<<sum_of_natural_number(n);

    int sum=0;
     for(int i=0;i<=n;i++)
     {
        sum=sum+i;
     }
    
    //cout<<sum<<endl;

   // cout<<square_sum(n);

   cout<<cube_sum(n);


}

