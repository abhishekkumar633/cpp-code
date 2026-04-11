#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include <sstream>
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
pair<char,int> max_value(vector<pair<char,int>>&vec){
   
    pair<char,int>ans={};
    for(auto it:vec){
        if(it.second>ans.second){
            // ans=max(ans,it.second);
            ans=it;
        }
    }
    return ans;
}
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

  int n;
    cin >> n;

    vector<pair<char,int>> vec;

    for(int i = 0; i < n; i++){
        char ch;
        int freq;
        cin >> ch >> freq;

        vec.push_back({ch, freq});
    }
    pair<char,int>ans=max_value(vec);
    cout<<ans.first<<" "<<ans.second;

}