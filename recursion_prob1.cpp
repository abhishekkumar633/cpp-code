#include<iostream>
using namespace std;
void printeven(int num,int N){
// To handle base case
    if(num>N)
    return;
    cout<<num<<endl;
    printeven(num+2,N);
}

void checkeven(int num1){
    if(num1%2==0)
    cout<<"even number\n";
    else
     cout<<"odd number\n";
     
}

void printodd(int num2,int N){
// To handle base case
    if(num2>N)
    return;
    cout<<num2<<endl;
    printeven(num2+2,N);
}
int main()
{
    int N;
    cout<<"enter the nummber to print an even\n";
    cin>>N;

   printeven(2,N);

   int num1;
    cout<<"enter the nummber to check an even\n";
    cin>>num1;
    checkeven(num1);

    int num2;
    cout<<"enter the nummber to print an odd\n";
    cin>>num2;
    printodd(1,num2);

}