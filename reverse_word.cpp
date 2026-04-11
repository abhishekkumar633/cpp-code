#include<iostream>
using namespace std;
string reverse(string str){
    int start=0,end=str.size()-1;
    while(start<end)
    {
        if(str[start]!=str[end]){
            swap(str[start],str[end]);
        }
       
        start++;
        end--;
    }
    return str;
}
int main()
{
   string str="abhishek";
   cout<<reverse(str);
}