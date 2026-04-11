#include<iostream>
#include<vector>
using namespace std;
int longest_substring_uniquechar(string str){
    vector<bool>count(256,0);
    int first=0,second=0,len=0;
    while(second<str.size()){

        while(count[str[second]]) // loop is used to check repetition
        {
            count[str[first]]=0;
            first++;
        }
            count[str[second]]=1;
            len=max(len,second-first+1);
            second++;
    }  

    return len;
    
}
int main()
{
    string str;
    cout<<"enter the string\n";
    getline(cin,str);

    cout<<"final output is\n"<<longest_substring_uniquechar(str);
}