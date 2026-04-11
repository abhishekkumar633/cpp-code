#include<iostream>
using namespace std;
int sum_of_digit(int x){
    int sum=0;
    while(x>0)
    {
        int digit=x%10;
        sum += digit;
        x /= 10;
    }

    return sum;
}

int main()
{
    cout<< sum_of_digit(12345);
}