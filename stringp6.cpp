#include<iostream>
#include<vector>
using namespace std;
string sort_vowel(string str){
    vector<int>upper(26,0);
    vector<int>lower(26,0);

    // now store the count of vowel of both upper and lowercase letter
    for(int i=0;i<str.size();i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            lower[str[i]-'a']++;
            str[i]='#';
        }
       else if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
            upper[str[i]-'A']++;
            str[i]='#';
    }
}

// now store vowel sorted string in ans
    string ans;
    for(int i=0;i<26;i++){
        // upper case sorted
        char c='A'+i;
        while(upper[i]){
            ans += c;
            upper[i]--;
        }
    }

    // lower case sorted
    for(int i=0;i<26;i++){
        char c='a'+i;
        while(lower[i]){
            ans += c;
            lower[i]--;
        }
    }

    // now Updation code in final string 
    int first=0,second=0;
    while(second<ans.size()){
        if(str[first]=='#'){
           str[first] =ans[second];
           second++;
        }
        first++;
    }
    return str;
 }
int main()
{
    string str;  
    cout<<"enter the string";
    getline(cin,str);
    cout<<"final string is"<<sort_vowel(str);
}


