#include<iostream>
using namespace std;
int sqrt(int x)
{
    int start=0,end=x,mid,ans=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(mid*mid==x)
        return mid;
        else if(mid*mid<x){
            ans += mid;
            start=mid+1;           
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main()
{
    int x;
    cout<<"enter the no whom u want to find sqrt\n";
    cin>>x;
     cout << "The integer square root of " << x << " is: " << sqrt(x) << endl;
    return 0;
}

