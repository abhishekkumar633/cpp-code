#include<iostream>
#include<vector>
using namespace std;
int smallest_distinct_window(string str){
    vector<int>count(256,0);
    int first=0,second=0,diff=0,len=str.size();
    // To find out diffrent character in an given string array
    while(first<str.size()){
        if(count[str[first]]==0)
        {
             diff++;  // to store different character
             count[str[first]]++;
             first++;
        }
    }
 for(int i=0;i<256;i++)
 {
    count[i]=0;
    first=0;
 }
while(second<str.size()){
    while(diff && second<str.size()){
        if(count[str[second]]==0)
        {
            diff--;
            count[str[second]]++;
            second++;
        }
    }
}
    len=min(len,second-first);
    while(diff!=1)
    {
        len = min(len,second-first);
        count[str[first]]--;
        if(count[str[first]]==0);
       { 
            diff++;
            first++;
        }
    }
 return len;
}
int main()
{
    string str;
    cout<<"enter the string\n";
    getline(cin,str);

    cout<<"final output is\n"<<smallest_distinct_window(str);
}
