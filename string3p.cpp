#include<iostream>
#include<vector>
using namespace std;
string sorted_string(string str){
    vector<int>alpha(26,0);

    for(int i=0;i<str.size();i++){
        alpha[str[i]-'a']++;
    }

    string ans;
    for(int i=0;i<26;i++){
        char c='a'+i;
        while(alpha[i]){
            ans+=c;
            alpha[i]--;
        }
    }
 return ans;
}
int main()
{
    string str;
    cout<<"enter the string";
    getline(cin,str);

 string output = sorted_string(str);
 cout<<"sorted string is\n"<<output<<endl;
}