#include<iostream>
using namespace std;
// void changesign(int *p){
// *p=(*p)*-1;
// cout<<p<<" ";
// }

void square(int *p){
    int a=10;
    p=&a;
    *p=(*p)*(*p);
    cout<<*p<<endl;
}
int main()
{
//   void swap(char *x,char *y){
//     char *t=x;
//     x=y;
//     y=t;
    
// }
//   int main()
//   {
//        float f=10.5;
//        float p=2.5;
//        float* ptr=&f;
//        (*ptr)++;
//        *ptr=p;
//        //cout<<*ptr<<" "<<f<<" "<<p<<" ";

//       int a =7;
//       int b=17;
//       int *c=&b;
//       *c=7;
//      // cout<<a<<" "<<b<<endl;

//     int *ptr =0;
//     int a1=10;
//     *ptr=a1;
//     cout<<*ptr<<endl;

// int b=10;
// int *a2=&b;
// cout<<*a2<<endl;

// int a=7;
// int *c=&a;
// c=c+1;
// cout<<a<<" "<<*c<<endl;

// int arr[]={4,5,6,7};
// int *p=(arr+1);
// cout<<*arr+9;

// char arr[20];
// int i;
// for(int i=0;i<10;i++)
// {
//     *(arr+i)=65+i;
// }
//  *(arr+i)='\0';

//  //for(int i=0;i<10;i++)
//  cout<<arr<<" ";
 
//  float arr1[5]={12.5,10.0,13.5,90.5,0.5};
//  float *ptr1=&arr1[0];
//  float *ptr2= ptr1+3;
//  cout<<*ptr2<<" ";
//  cout<<ptr2-ptr1;
//  return 0;

// char *x="ninjasquiz";
// char *y="codingninjas";
// char *t;
// swap(x,y);
// cout<<x<<" "<<y;
// t=x;
// x=y;
// y=t;
// cout<<" "<<x<<" "<<y;

// int a=10;
// changesign(&a);
// cout<<a<<endl;
// cout<<&a<<endl;


int a=10;
square(&a);
cout<<a<<endl;

}


 
   
  