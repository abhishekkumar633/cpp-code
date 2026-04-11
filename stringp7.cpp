#include<iostream>
#include<algorithm>
using namespace std;
string add_string(string num1,string num2){

    if(num1.size()<num2.size()) // considering num1 is greater...
    swap(num1,num2);
    int index1=num1.size()-1,index2=num2.size()-1;
    int carry=0,sum;
    string ans; // for storation purpose of the addition string
    // index2>=0;

    while(index2>=0){
        sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
        carry=sum/10;
        char c='0'+sum%10;
        ans += c;
        index2--;index1--;      
    }
    // for index 1
    while(index1>=0){
        sum=(num1[index1]-'0')+carry;
        carry=sum/10;
        char c='0'+sum%10;
        ans += c;
        index1--;
    }

    if(carry)
   { 
    ans += '1';
   }
  reverse(ans.begin(), ans.end());
    return ans;
    
    
}
int main()
{
    string num1;
    string num2;
    string num3;
    cout<<"enter first string\n";
    getline(cin,num1);
    cout<<"enter second string\n";
    getline(cin,num2);

      

    cout<<"addition of result is"<<add_string(num1,num2);
}