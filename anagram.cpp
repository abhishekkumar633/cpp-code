#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

// solving using sorting approach
bool check_anagram(string a,string b){
    if(a.size() != b.size())
        return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
}

// solving through frequency count
bool check_Anagram(string a,string b){
    vector<int>freq(26,0);
    if(a.size() != b.size()){
        return false;
    }
    for(char c:a) freq[c-'a']++;
    for(char c:b) freq[c-'a']--;

    for(int count:freq){
        if(count != 0)
            return false;
    }
    return true;

}

// remove Duplicate character from given string
 string remove_duplicate(string str){
    vector<int>freq(26,0); // here it is in ascii where character automatically goes into their correct postion;
    string result = "";
    for(char c : str){
        if(freq[c-'a'] == 0){ // not seen element before
            result += c;
            freq[c-'a']=1;
        }
    }
    return result;
 }

 // remove Duplicate character from given string
//  string remove_duplicate(string str){
//     vector<int>freq(256,0); // here it is in ascii where character automatically goes into their correct postion;
//     string result = "";
//     for(char c : str){
//         if(freq[c] == 0){ // not seen element before
//             result += c;
//             freq[c]=1;
//         }
//     }
//     return result;
//  }

 // reverse a string sentence

 string reverse_sentence(string str){
    stringstream ss(str); // this will convert words into object 
    string word;
    vector<string>words;
    while(ss >> word){
        words.push_back(word);
    }
    string result = "";
    for(int i=words.size()-1;i>=0;i--){
        result += words[i];
        if(i>0)  result += " ";
    }
    return result;
 }

 // reverse the sentence 
 string reverse_sentence(string str){
    stringstream ss(str); // this will convert sentence into word;
    string word;
    vector<string>words;
    while(ss >> word){
        words.push_back(word);
    }
    string result=" ";
    for(int i=words.size()-1;i>=0;i--){
        result += words[i];
    }
    return result;

 }

//palindrome question
bool isPalindrome(string a){
    int start=0,end=a.size()-1;
    while(start<=end){ 
        if(a[start] != a[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

//reverse a string
 string reverse(string str){
    int start=0,end=str.size()-1;
    while(start < end){
        if(str[start] != str[end]){
            swap(str[start],str[end]);
            start++;
            end--;
        }
    }
    return str;
 }
 // count vowels and consonant in a string
 pair<int,int> count_vow_cons(string str){
    int vowel = 0,consonant=0;

    for(int i=0;i<str.size();i++){
        char c = tolower(str[i]);
        if(isalpha(c)){
             if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            vowel++;
        }
        else{
            consonant++;
        }
        }       
    }
    return {vowel,consonant};
 }

//String compression (like Run-Length Encoding) e.g aaabbccddd=a3b2c2d3;
string length_encoding(string str){
    string result="";
    for(int i=0;i<str.size();i++){
        int count=1;
        while(i<str.size() && str[i]==str[i+1]){
            count++;
            i++;            
        }
        result += str[i];
        result += to_string(count);
    }
    return result;
}

// find the first non-repeating character
char first_non_repeating_character(string str){
    vector<int>freq(256,0);
    for(char c:str){
        freq[c]++;
    }
        for(char c:str){
            if(freq[c]==1)
            return c;
        }
        return '\0'; // return null if not found
}

//check if string input is a subsequence of string given. by using two pointer approach

bool check_subsequence(string input,string given){
    int i=0,j=0;
    while(i<input.size() && j<given.size()){
        if(input[i]==given[j]){
            i++;
        }
        j++;
    }
    return i==input.size();
}

// longest prefix of a string
string longest_prefix(vector<string>&str){
    string prefix=str[0];
    for(int i=1;i<str.size();i++){
        while(str[i].find(prefix)!=0){ // this one is matching each character of the string
            prefix = prefix.substr(0,prefix.size()-1); // this one is cutting last character of the string
            if(prefix.empty()) return "";
        }
    }
    return prefix;
}

// check valid palindrome (Ignore non-alphanumeric);
bool IsPalindrome(string str){
    int start=0,end=str.size()-1;
    while(start < end){
          while(start < end && !isalnum(str[start])) start++;
          while(start < end && !isalnum(str[end]))    end--;        
            if(tolower(str[start]) != tolower(str[end]))
            return false;
            start++;
            end--;    
    }
    return true;
}

// group anagram using hashmap and sorting technique
vector<vector<string>> group_Anagram(vector<string>str){
    unordered_map<string,vector<string>>mp;
   
    for(string s:str){
        string key=s;
        sort(key.begin(),key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>>result;
    for(auto &pair:mp){
        result.push_back(pair.second); 
    }
    return result;
} 

// add all # first then add remaining character
string characterfirst(string str) {
    string result,character;
    for(int i=0;i<str.size();i++){
        if(str[i]=='#'){
            result += str[i];
        }
    }
    for(int i=0;i<str.size();i++){
        if(str[i] !='#'){
            character += str[i];
        }
    }
    return result + character;
}

// count all character and add after all character
string reduce_stringsize(string str){
    vector<int>freq(26,0);
    for(char c : str){
        freq[c-'a']++;
    }
    string result;
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            result += char('a'+i);
            result += to_string(freq[i]);
        }     
    }
    return result;
}

 //Given an array of integers return factors of every number present in the array answer was expected as total number of such numbers which werre present in array 
//Pretty straightforward I guess brute force n² or map can be used 

vector<vector<int>> factorOfAllNumber(vector<int>arr){
    vector<vector<int>>result;
    for(int i=0;i<arr.size();i++){
        vector<int>factor; //here every time factor is getting updated
        for(int j=1;j<=arr[i];j++){
            if(arr[i] % j == 0){
                factor.push_back(j);
            }
        }
        result.push_back(factor);
    }
    return result;                                                                                        
}

// count the freq of each number

unordered_map<int,int> countFreq(vector<int>arr){
    unordered_map<int,int>freq;
    for(int num : arr){
        freq[num]++;
    }
    return freq;
}

int main(){
   // cout<<(check_Anagram("listen","silent") ? "yes" :"No");
    //cout<<isPalindrome("madam");
    //cout<<reverse("hello");
   // cout<<remove_duplicate("programming");s
    //cout<<reverse_sentence("this is Abhishek speaking");
    // string str="Hello This is 123";
    // auto result = count_vow_cons(str);
    // cout<<"vowels are:"<<result.first<<endl<<"consonant are:"<<result.second;
    //cout<<length_encoding("aaabbcceess");
    //cout<<first_non_repeating_character("aaabbcd");
    // int n;
    // vector<string>str(n);    
    // cout<<"enter the size of array of string"<<endl;
    // cin>>n;
    // cout<<"enter string"<<endl;
    // for(int i=0;i<n;i++){
    //     string temp;
    //     cin>>temp;
    //     str.push_back(temp);
    // }
//     vector<string> str;
// int n;
// cout << "Enter the size of array of string: ";
// cin >> n;

// for (int i = 0; i < n; i++) {
//     string temp;
//     cin >> temp;
//     str.push_back(temp);  // add string to vector
// }
// vector<string> str = {"flower","flow","flight"};
//     cout << "Longest Common Prefix: " << longest_prefix(str) << endl;
//     return 0;
//cout<<characterfirst("abhi###shek##");
//cout<<reduce_stringsize("aabbhishhekkaa");
 vector<int> arr = {6, 12, 15,0,20};
 auto freq=countFreq(arr);
    vector<vector<int>> ans = factorOfAllNumber(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << arr[i] << ": ";
        for (int f : ans[i]) 
        cout << f << " ";
        cout << endl;
    }

    
   // cout<<check_subsequence("abc","ascblc");
   //cout << "Longest Common Prefix: " << longest_prefix(str) << endl;
  // cout<<longest_prefix(str);
}