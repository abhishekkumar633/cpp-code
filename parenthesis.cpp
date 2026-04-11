#include<iostream>
#include<vector>
using namespace std;
void Generate_parenthesis(int n,int left,int right,vector<string> &ans,string &temp){

    if(left+right==2*n)
    {
         ans.push_back(temp);
         return;
    }
// left part check
    if(n>left)
    {
        temp.push_back('(');
        Generate_parenthesis(n,left+1,right,ans,temp);
        temp.pop_back();
    }

    // right part check

    if(left>right)
    {
         temp.push_back(')');
        Generate_parenthesis(n,left,right+1,ans,temp);
        temp.pop_back();
    }

    
}
int main()
{
    int n ,left=0,right=0;
    vector<string>ans;
    string temp;
    //string str;
    cout<<"enter the size of parenthesis\n";
    cin>>n;
    Generate_parenthesis(n,left,right,ans,temp);

       cout << "Generated balanced parentheses:\n";
    for (const string &s : ans) {
        cout << s << endl;
    }




}