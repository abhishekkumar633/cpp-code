#include<iostream>
#include<vector>
using namespace std;

// To sort a given string in a correct sentence form...

string sort_string(string str){
    vector<string>ans(10);
    int count=0,index=0;
    string temp; // temporary variable of string to gather all the words of a given input string
    while(index<str.size()){
        if(str[index] ==' '){
            int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
        }

        else{
            temp += str[index];
           
        }
         index++;
    }
    int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;

    // now accessing the string from ans to print in our final 0utput

    for(int i=0;i<=count;i++){
        temp += ans[i];
       if (index != count) {
            temp += ' ';  // Add space between words
        }
    }

    return temp;
}
int main()
{
    string str;
    cout<<"enter the string\n";
    getline(cin,str);

    cout<<"our sentence of string is:\n"<<sort_string(str);

}