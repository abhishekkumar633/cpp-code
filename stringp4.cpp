#include<iostream>
#include<vector>
using namespace std;
int longest_palindrome_substring(string str){
    vector<int>lower(26,0);
    vector<int>upper(26,0);

    // To store count of each character of a given string
   
    for(int i=0;i<str.size()-1;i++) // count total no of character in a string and store in a lower and upper array box
    {
        if(str[i]>='a')
        lower[str[i]-'a']++;
            else{
               upper[str[i]-'A']++;
            }
       }
        int count=0;
        bool odd=0;

        // Now simply iterate on each character and return count
 
        for(int i=0;i<26;i++){
            if(lower[i]%2==0)
            count += lower[i];
            else{
                count += lower[i]-1;
                odd=1;
            }
            if(upper[i]%2==0)
            count += upper[i];
            else{
                count += upper[i]-1;
                odd=1;
            }
        }
        return count+odd;
}
int main(){
    string str;
    cout<<"enter the string\n";
    getline(cin,str);

    cout<<"the length of the longest palindrome is "<<longest_palindrome_substring(str);
    
}