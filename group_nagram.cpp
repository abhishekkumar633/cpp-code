#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> group_anagram(vector<string> str){
    unordered_map<string ,vector<string>>mp;
    for(string s:str){
        string key=s;
        sort(key.begin(),key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>>result;
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}
int main(){
     vector<string> str = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = group_anagram(str);

    for(auto group : ans){
        for(auto word : group){
            cout << word << " ";
        }
        cout << endl;
    }
}