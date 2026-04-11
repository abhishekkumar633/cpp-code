#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPangram(const string& str){
    vector<bool>alpha(26,false);
    for(int i=0;i<str.size();i++){
        if(isalpha(str[i])){
             char ch=tolower(str[i]);
             alpha[ch-'a'] = true; 
        }           // this line is used to assign 1 in every box when that particular letter comes
    }

    for (int i=0;i<26;i++){
        if(alpha[i] == false)  // to check whether any box is left out with zero or not
        return 0;
    }
    return 1;   
}
int main(){
   string str;
   cout<<"enter the sentence of string\n";
   getline(cin,str);

   if (isPangram(str)){
     cout << "The sentence is a pangram!" << endl;
   }
    else{
        cout << "The sentence is not a pangram!" << endl;
    }

}