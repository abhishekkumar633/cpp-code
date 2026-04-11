#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_set>
using namespace std;
char first_non_repeating_character(string str)
{
    vector<int> count(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[str[i] - 'a'] == 1)
            return str[i];
    }
    return '\0';
}

int count_word(string &str)
{
    int count = 0, i;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

string remove_character(string str, char target)
{
    string result;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != target)
            result += str[i]; // To store modified string in result string variable...
    }
    return result;
}

char most_frequent_character(string str)
{

    vector<int> count(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        count[str[i] - 'a']++;
    }
    int maximum_count = 0;
    char result1;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maximum_count)
        {
            maximum_count = count[i];
            result1 = i + 'a';
        }
    }

    return result1;
}
void rotateclockwise(string &str1)
{
    int index = str1.size() - 2;
    char c = str1[str1.size() - 1];
    while (index >= 0)
    {
        str1[index + 1] = str1[index];
        index--;
    }
}

bool is_rotaed(string str1, string str2)
{
    string clockwise, anticlockwise;

    clockwise = str1;
    rotateclockwise(clockwise);
    rotateclockwise(clockwise);
    if (clockwise == str2)
    {
        return 1;
    }

    return 0;

    //    anticlockwise=str1;
    //      rotateanticlockwise( anticlockwise);
    //      rotateanticlockwise( anticlockwise);
    //       if(anticlockwise==str2)
    //       return 1;
}

void substring(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << str.substr(i, j - i + 1) << endl; // library function
        }
    }
}

int unique_longest_substring(string str)
{
    int n = str.size();
    int maximum_length = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<char> unique_char;
        int current_length = 0;

        for (int j = i; j < n; j++)
        {
            if (unique_char.find(str[j]) != unique_char.end())
            {
                break;
            }
            unique_char.insert(str[j]);
            current_length++;
        }

        maximum_length = max(maximum_length, current_length);
    }
    return maximum_length;
}

string longest_prefix(string str)
{
    int n = str.size();
    // for(int i=n-1;i>0;i--)
    for (int i = 1; i <= n; i++)
    {
        if (str.substr(0, i) == str.substr(n - i, i))
        {
            return str.substr(0, i);
        }
    }
}

int length_of_longest_substring(string str)
{
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;
    while (second < str.size())
    {
        while (count[str[second]]) // To check repetition of a character liding window protocol
        {
            count[str[first]] = 0;
            first++;
        }
        count[str[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }

    return len;
}

int unique_character(string str)
{
    int len = str.size();
    int first = 0, second = 0, diff = 0;
    vector<int> count(256, 0);
    while (first < str.size())
    {
        if (count[str[first]] == 0)
        {
            diff++;
            count[str[first]]++;
        }
        first++;
    }
    // return diff;

     first = 0;
    for (int i = 0; i < 256; i++)
        count[i] = 0;

    while (second < str.size())
    {
        while (diff && second < str.size())
        {
            if (count[str[second]] == 0)
                diff--;

            count[str[second]]++;
            second++;
        }

        len = min(len, second - first);

        while (diff != 1)
        {
            len = min(len, second - first);
            count[str[first]]--;

            if (count[str[first]] == 0)
                diff++;
            first++;
        }
    }

    return len;
}

int string_matching(string str1,string str2){
    int n=str1.size() , m=str2.size();
    for(int i=0;i<=n-m;i++)
    {
       int first =i ,second=0;
       while(second<m){
        if(str1[first] != str2[second]){
            break;
        }
        else
            first++;
            second++;
       }
       if(second==m)
       return first-second;
    }

    return -1;

}

int main()
{
    string str1;
    string str2;
    string str;
    char target;
    cout<<"enter first string\n";
    getline(cin,str1);

     cout<<"enter second string\n";
    getline(cin,str2);

    // cout << "enter string\n";
    // getline(cin, str);
    // cout<<first_non_repeating_character(str);

    // cout<<count_word(str);

    //    cout<<"enter target character to delete\n";
    //    cin>>target;

    //    cout<<"modified sting is :"<<remove_character(str,target);

    // cout<<"most frequent character is :"<<most_frequent_character(str);
    // cout<<is_rotaed( str1,str2);

    // substring(str);

    // cout<< unique_longest_substring(str);

    // cout<<longest_prefix(str);

    // cout<<length_of_longest_substring(str);

    //cout << unique_character(str);

   cout<<string_matching(str1,str2);
}