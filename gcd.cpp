#include<iostream>
using namespace std;
void gcd_of_two_number(int n1,int n2){

    if(n2==0)
    {
        cout<<"result is "<<n1;
    }

    gcd_of_two_number(n2,n1%n2);
}

int  climbing_stair(int n){
    if(n<=1)
    return 1;
 
    return climbing_stair(n-1) + climbing_stair(n-2);

}
int main()
{
    int n1,n2,n;
    // cout<<"enter first number\n";
    // cin>>n1;
    // cout<<"enter second number\n";
    // cin>>n2;
    //  gcd_of_two_number(n1,n2);

    cout<<"enter stair number\n";
    cin>>n;

     climbing_stair( n);
}