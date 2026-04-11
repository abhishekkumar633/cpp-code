#include<iostream>
#include<vector>
using namespace std;
string  background_string_compare(string str){
    vector<char>st;
    vector<char>temp;
    for(int i=0;i<str.size();i++)
    {
        if(st.empty() && str[i] != '#')
        st.push_back(str[i]);

        else if(str[i]=='#')
         st.pop_back();

         else
             st.push_back(str[i]);
    }
 
 for(int i=0;i<st.size();i++)
 {
    temp.push_back(st[i]);
 }
  string result(temp.begin(), temp.end()); // to convert vector temp into string

    return result;

}
int main()
{
    string str = "abc#d##ef#g#";
    string result = background_string_compare(str);
    cout << "Processed string: " << result << endl;
    return 0;
}