#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;
double discounted_amount(int amount){
    double value,ans;
    if(amount < 1000){
        value=(amount*95)/100;
        ans=round(value*100)/100;
    }
    else if(amount >=1000 && amount<5000){
        value=(amount*90)/100;
         ans=round(value*100)/100;
    }
    else {
        value=(amount*85)/100;
        ans=round(value*100)/100;
    }
    return ans;
}
int main(){
    int amount;
    cout<<"enter amount:";
    cin>>amount;
    cout<<discounted_amount(amount);
}