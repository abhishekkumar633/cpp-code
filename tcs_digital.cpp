#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include <sstream>
#include<unordered_set>
using namespace std;
int max_sum_subArray(vector<int>arr){
    int sum=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int curr_sum=0;
        for(int j=i;j<arr.size();j++){
            curr_sum += arr[j];
            if(curr_sum<0){
                curr_sum=0;
            }
            else{
                sum=max(sum,curr_sum);
            }
        }
    }
    return sum;
}
// int max_sum_subArray(vector<int>arr){
//     int sum=INT_MIN;
//     for(int i=0;i<arr.size();i++){
//         int curr_sum=0;
//         for(int j=i;j<arr.size();j++){
//             curr_sum += arr[j];
//             if(curr_sum<0){
//                 curr_sum=0;
//             }
//             else{
//                 sum=max(sum,curr_sum);
//             }
//         }
//     }
//     return sum;
// }
vector<int> kadane_algorithm(vector<int>arr){
    int maxi,prefix=0,sum=INT_MIN;
    vector<int>ans;
    vector<int>best;
    maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        prefix += arr[i];
        ans.push_back(arr[i]);
        if(prefix>sum){
            sum=prefix;
            best=ans;
        }
        if(prefix<0){
            prefix=0;
            ans.clear();
        }
        
    }
    return best;
}
// find min freq element and max freq element
pair<int,int> min_ele_max_ele(vector<int>arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int cur_min=INT_MAX;
    int cur_max=INT_MIN;
     int min_ele = -1, max_ele = -1;
    for(auto it:mp){
        if(it.second < cur_min){
            cur_min=it.second;
            min_ele=it.first;
        }
        if(it.second > cur_max){
            cur_max=it.second;
            max_ele=it.first;
        }
    }
  return {cur_min,cur_max};
}

int delete_every_3rd_eleOf_array(vector<int>arr,int k){
    int index=0;
    while(arr.size()>1){
        index=(index+k-1)%arr.size();
        arr.erase(arr.begin()+index);
    }
    return arr[0];
}

int max_sum_subArray2(vector<int>arr){
    int ans=INT_MIN,sum=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }      
    }
    return ans;
}
bool cmp(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
}
vector<char> sort_charBy_freq(string str){
    unordered_map<char,int>mp;
    for(char x:str){
        mp[x]++;
    }
    vector<char>ans;
    vector<pair<char,int>>vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end(),cmp);
    for(auto it:vec){
        ans.push_back(it.first);
    }
    return ans;
}
int at_most_k(string str,int k){
    unordered_map<char,int>mp;
    int left=0,right=0,count=0;
    for(right=0;right<str.size();right++){
        mp[str[right]]++;
        while(mp.size()>k){
            mp[str[left]]--;
            if(mp[str[left]]==0){
                mp.erase(str[left]);
            }
            left++;
        }
        count += right-left+1;
    }
    return count;
}
int count_exactly_k_ele_subarray(string str,int k){
    return at_most_k(str,k)-at_most_k(str,k-1);
}

string count_char_and_appendTheir_freq(string str){
    unordered_map<char,int>mp;
    for(char x:str){
        mp[x]++;
    }
    vector<pair<char,int>>vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end());
    string ans;
    for(auto it:vec){
        ans += it.first + to_string(it.second); // or ans += it.first and ans += to_string(it.second);
    }
return ans;
}

bool cmp2(pair<char,int>&a,pair<char,int>&b){
    return a.first>b.first; // used for sorting in descending order of character 
}
bool cmp1(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second; // used for sorting the character by frequency;
}
string count_char_and_appendTheir_freq2(string str){
    unordered_map<char,int>mp;
    for(char x:str){
        mp[x]++;
    }
    vector<pair<char,int>>vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end(),cmp1);
    string ans;
    for(auto it:vec){
        ans += it.first + to_string(it.second); // or ans += it.first and ans += to_string(it.second);
    }
return ans;
}
string reverse_words(string str){
    stringstream ss(str);
    vector<string>words;
    string word;
    while(ss >> word){
        words.push_back(word);
    }
    reverse(words.begin(),words.end());
    string ans;
    for(int i=0;i<words.size();i++){
        ans += words[i];
        ans += " ";
       }
       return ans;
}
// generate all substrings one wise one and count their freq and subtract max freq with min freq and add to the sum
int sumOf_beautyOf_substring(string str){ 
    int sum=0;
    for(int i=0;i<str.size();i++){
        unordered_map<char,int>mp;
            for(int j=i;j<str.size();j++){
                mp[str[j]]++;

                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(auto it : mp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum += maxi-mini;
            }
    }
    return sum;
}

int sumOf_beautyOf_substring(string str){
    int sum=0;
    for(int i=0;i<str.size();i++){
        vector<int>freq(26,0);
        for(int j=i;j<str.size();j++){
            freq[str[j]-'a']++;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int k=0;k<26;k++){
            if(freq[k]>0){}
            maxi=max(maxi,freq[k]);
            mini=min(mini,freq[k]);
        }
        sum += maxi-mini;
    }
    return sum;
}
pair<char,int> max_value(vector<pair<char,int>>&vec){
   
    pair<char,int>ans={};
    for(auto it:vec){
        if(it.second>ans.second){
          //  ans=max(ans,it.second);
            ans=it;
        }
    }
    return ans;
}
bool isPalindrome(string ans){
    int start=0,end=ans.size()-1;
    while(start<end){
        if(ans[start] != ans[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int   longest_palindrome_substring(string str){
    int maxi=INT_MIN;
    for(int i=0;i<str.size();i++){
        int count=0;
        string ans="";       
        for(int j=i;j<str.size();j++){
            ans += str[j];
           if(isPalindrome(ans)){           
                count = j-i+1;               
                maxi=max(maxi,count);                
            }
        }
    }
    return maxi;
}

string longest_palindrome_substring2(string str){
    int maxi=INT_MIN;
    string best="";
    for(int i=0;i<str.size();i++){
        int count=0;
        string ans="";       
        for(int j=i;j<str.size();j++){
            ans += str[j];
           if(isPalindrome(ans)){     
              count=j-i+1;      
               if(count>maxi){
                    maxi=count;
                    best=ans;
               }               
            }
        }
    }
    return best;
}
// ["flower","flight","flow"] output "fl";
 string longestCommonPrefix(vector<string>& strs) { 
        if(strs.empty()) {
            return "";
        }
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        int min_len=min(first.size(),last.size());
        string ans="";
        for(int i=0;i<min_len;i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }
        return ans;
}

bool isAnagram(string str1,string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    return str1==str2;

}
bool isAnagram2(string str1,string str2){
     if(str1.size() != str2.size()){
        return false;
    }
    vector<int>freq(26,0);
    for(int i=0;i<str1.size();i++){
        freq[str1[i]-'A']++;
    }
     for(int i=0;i<str2.size();i++){
        freq[str2[i]-'A']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}
bool rotationOf_another_string(string str,string goal){
    if(str.size() != goal.size()) return false;
    for(int i=0;i<str.size();i++){
        char first=str[0];
        str.erase(0,1);
        str.push_back(first);
        if(str==goal){
            return true;
        }
    }
    return false;
}

bool IsOdd(int num){
    if(num % 2 != 0){
        return true;
    }
    return false;
}

string longest_odd_numberString(string str){
    int maxi=INT_MIN;
    string ans="";
    for(int i=0;i<str.size();i++){
        string temp="";
        for(int j=i;j<str.size();j++){
            temp += str[j];
            if((temp.back()-'0') % 2 != 0){
              if(temp.size()>maxi){
                maxi=temp.size();
                ans=temp;
              }
            }
        }
    }
    return ans;
}
string longest_odd_numberString2(string str){
    string ans="";
    for(int i=str.size()-1;i>=0;i++){
        if((str[i]-'0') %2 != 0){
            return str.substr(0,i+1);
        }
    }
    return "";
}

// Now binary search problem
int count_occurrences_of_specific_ele(vector<int>arr,int k){
    unordered_map<int,int>mp;
    for(int num :arr){
        mp[num]++;
    }
    for(auto it:mp){
        if(it.first == k){
            return it.second;
        }
    }
}
int rotated_array(vector<int>arr,vector<int>goal){
    for(int i=0;i<arr.size();i++){
         if(arr==goal){
            return i;
        }
        int first=arr[0];
        arr.erase(arr.begin());
        arr.push_back(first);
        int count=0;      
    }
    return -1;
}

// Bit manipulation question
bool check_powerOf_2(int n){
    if(n>0){
        return ((n&(n-1))==0);
    }
    else return 0;
}

int max_diff(vector<int>arr,int k){
    sort(arr.begin(),arr.end());
    vector<int>ans1;
    int result1,result2=INT_MIN;
    for(int i=0;i<3;i++){
        ans1.push_back(arr[i]);
        result1=arr[0];

    }
}

vector<int> remove_duplicate_reverse(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    vector<int>ans;
    for(auto it:mp){
        if(it.second == 1 ){
            ans.push_back(it.first);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> remove_duplicate_reverse3(vector<int>&arr){
    vector<int>freq(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    vector<int>ans;
    for(int i=1;i<=freq.size();i++){
        if(freq[i]==1){
            ans.push_back(i);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
pair<int,int> no_of_rotation(vector<int>&arr ,vector<int>&goal,int target){
    int desired_idx=-1,rotation=-1;
    for(int i=0;i<arr.size();i++){
         if(arr==goal){
           rotation=i;
           break;
        }   
        int first=arr[0];
        arr.erase(arr.begin());
        arr.push_back(first);          
    }
    for(int i=0;i<goal.size();i++){
        if(goal[i]==target){
            desired_idx=i;
            break;
        }
    }
    return {rotation,desired_idx};
}

vector<string> remove_duplicateAnd_keep_one(vector<string>&fruits){
    unordered_set<string>seen;
    vector<string>ans;
    for(auto it:fruits){
        if(seen.find(it)==seen.end()){
            ans.push_back(it);
            seen.insert(it);
        }
    }
    return ans;
}

vector<int> move_zerTo_end(vector<int>arr){
    int start=0,end=arr.size()-1;
    for(int start=0;start<end;start++){
        if(arr[start]==0){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        else{
            start++;
        }
    }
    return arr;
}

void move_zeroTo_end(vector<int>&arr){
    int left=0;
    for(int right=0;right<arr.size();right++){
        if(arr[right] != 0){
            swap(arr[right],arr[left]);
            left++;
        }
    }
}
bool cmp4(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int most_frequent_number(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    // vector<pair<int,int>>ans;
    // for(auto it:mp){
    //     if(it.second > 1){
    //         ans.push_back(it);
    //     }
    // }
    // sort(ans.begin(),ans.end());
    int fin_ans=INT_MIN,val=-1;
      for(auto it : mp){
       //fin_ans=min(fin_ans,it.second);
        if(it.second>fin_ans){
            fin_ans=it.second;
            val=it.first;
        }
    }
    return val;
}
bool cmp5(pair<int,int>& a, pair<int,int>& b){
    // if(a.second == b.second){
    //     return a.first < b.first; // smaller value first 
    //     return a.second > b.second; // most freq first
    // }
     return a.first < b.first;
     return a.second > b.second;
}

vector<int> sortByMaxFreq(vector<int> arr){
    unordered_map<int,int> mp;

    for(int x : arr){
        mp[x]++;
    }

    vector<pair<int,int>> v;
    for(auto it : mp){
        v.push_back(it); 
    }

    sort(v.begin(), v.end(),cmp5);

    vector<int> ans;

   
    for(auto p : v){
        for(int i = 0; i < p.second; i++){
            ans.push_back(p.first);
        }
    }

    return ans;
}

int third_largest_ele(vector<int>arr){
     int max_val1 = INT_MIN, max_val2 = INT_MIN, max_val3 = INT_MIN;
    for(int i=0;i<arr.size();i++){
        max_val1=max(arr[i],max_val1);;
    }
     for(int i=0;i<arr.size();i++){
        if(arr[i] != max_val2){
              max_val2=max(arr[i],max_val1);
        }     
    }
     for(int i=0;i<arr.size();i++){
        if(arr[i] != max_val1 && arr[i] != max_val3){
              max_val3=max(arr[i],max_val3);
        }     
    }
    return max_val3;

}
int third_largest_ele1(vector<int> arr) {
    int max_val1 = INT_MIN, max_val2 = INT_MIN, max_val3 = INT_MIN;

   
    for (int i = 0; i < arr.size(); i++) {
        max_val1 = max(arr[i], max_val1);
    }

    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != max_val1) {
            max_val2 = max(arr[i], max_val2);
        }
    }

    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != max_val1 && arr[i] != max_val2) {
            max_val3 = max(arr[i], max_val3);
        }
    }

    return max_val3;
}
int intersection_ofTwo_array(vector<int>arr1,vector<int>arr2){
    
}
// binary searcj in 2d matrix
int main(){
   // vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
//cout<<max_sum_subArray(arr); 
//cout<< kadane_algorithm(arr);
//   vector<int> arr = {1,1,2,2,2,3};

//     pair<int,int> result = min_ele_max_ele(arr);

//     cout << "Min freq element = " << result.first << endl;
//     cout << "Max freq element = " << result.second << endl;

//     return 0;
//  vector<int>arr={1,2,3,4,5,6,7};
//  cout<<delete_every_3rd_eleOf_array(arr,3);
 //vector<int>arr={2,3,5,-2,7,-4};
// vector<int>arr={-2,-3,-7,-2,-10,-4};
 //cout<<max_sum_subArray2(arr);
 //string str="raaaaj";
//  vector<char>ans=sort_charBy_freq(str);
//  for(char x:ans){
//     cout<<x<<" ";
//  }

//  string str= "abcbaa";
//  cout<<count_exactly_k_ele_subarray(str,3);

//  string str="bbbaaaacczzz";
//  cout<<count_char_and_appendTheir_freq2(str);
//  string str=" the  sky is blue ";
//  cout<<reverse_words(str);

//  string str="aabcbaa";
//  cout<<sumOf_beautyOf_substring(str);

//   int n;
//     cin >> n;

//     vector<pair<char,int>> vec;

//     for(int i = 0; i < n; i++){
//         char ch;
//         int freq;
//         cin >> ch >> freq;

//         vec.push_back({ch, freq});
//     }
//     pair<char,int>ans=max_value(vec);
//     cout<<ans.first<<" "<<ans.second;
    // string str= "cbbd";
    // cout<< longest_palindrome_substring2(str);
    // string Str1 = "CAT";
    // string Str2 = "AAT";

    // // Check if the strings are anagrams and output the result
    // if (isAnagram2(Str1, Str2))
    //     cout << "True" << endl;  // Output "True" if they are anagrams
    // else
    //     cout << "False" << endl;  // Output "False" if they aren't anagrams

    // return 0;

    //  string str1 = "rotation";
    //  string str2= "tionrota";

    // // Check if the strings are anagrams and output the result
    // if (rotationOf_another_string(str1, str2))
    //     cout << "True" << endl;  // Output "True" if they are anagrams
    // else
    //     cout << "False" << endl;  // Output "False" if they aren't anagrams

    // return 0;
    // string str="5347";
    // cout<<longest_odd_numberString(str);
    //  vector<int>arr={2,2,3,3,3,3,4};
    // cout<<count_occurrences_of_specific_ele(arr,4);
    //cout<<check_powerOf_2(16);
    vector<int>arr={2,1,1,3,4,5,5,6};
    vector<int>ans=remove_duplicate_reverse3(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
    
    // vector<string> fruits = {"apple", "banana", "apple", "orange", "banana"};

    // vector<string> ans = remove_duplicateAnd_keep_one(fruits);

    // for (auto &x : ans) {
    //     cout << x << " ";
    // }
    //vector<int>arr={4,4,5,6,5,5};
    // vector<int>arr={2,5,1,2,6,7,7,6};
    // cout<<most_frequent_number(arr);
    // vector<int>arr={2,5,2,8,5,6,8,8};
    // vector<int>ans=sortByMaxFreq(arr);
    // for(int x:ans){
    //     cout<<x<<" ";
    // }
    // vector<int>arr={8,2,1};
    // cout<<third_largest_ele1(arr);
    // vector<int>arr={1,0,3,4,0,6};
    // move_zeroTo_end(arr);
    // for(int x:arr){
    //     cout<<x<<" ";
    // }
}