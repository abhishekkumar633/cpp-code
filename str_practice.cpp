#include<iostream>
#include<vector>
using namespace std;
int longest_palindrome(string str){
    vector<int>lower(26,0);
    vector<int>upper(26,0);

    // To store count of each character
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]>='a')
        {
            lower[str[i]-'a']++;
        }

        else{
            upper[str[i]-'A']++;
        }
    }

    // iterate on each character of a string
    int count=0;
     bool odd=0;
    for(int i=0;i<26;i++)
    {
        if(lower[i]%2==0){
            count += lower[i];
        }

        else{
             count += lower[i]-1;
             odd=1;
        }

         if(upper[i]%2==0){
            count += upper[i];
        }

        else{
             count += upper[i]-1;
             odd=1;
        }
    }

    return count+odd;
}

string sort_character(string str){
    vector<int>alpha(26,0);
    for(int i=0;i<str.size()-1;i++)
        alpha[str[i]-'a']++;

        string ans;

        for(int i=0;i<26;i++){
            char c='a'+i;
            while(alpha[i])
            {
                ans += c;
                alpha[i]--;
            }
        }
    return ans;
}

string reverse_character(string str){
    int start=0,end=str.size()-1;
    while(start<end){
        swap(str[start],str[end]);
        start++;
        end--;
    }

    return str;
}

int count_vowel(string str){
    int sum=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
            sum += 1;
        }
    }
    return sum;
}

int main()
{
    string str;
    cout<<"enter the string\n";
    getline(cin,str);

   // cout<<"longest palindrome is:"<<longest_palindrome(str);

   //cout<<"sorted string is :"<<sort_character(str);

   //cout<<"reverse string is:"<<reverse_character(str);

   cout<<"total no of vowel are :"<< count_vowel(str);
}