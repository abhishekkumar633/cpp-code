#include<iostream>
#include<stack>
using namespace std;
bool check_paranthesis(string str){
    stack<int>st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        st.push(str[i]);
        else{
            if(st.empty())
            return 0;

            else{
                st.pop();
            }
        }
    }
    return st.empty();
}

bool check_paranthesis1(string str){
        stack<int>st;
        for(int i=0;i<str.size();i++)
        {
        if(str[i]=='(' ||str[i]=='{' ||str[i]=='[' )
            st.push(str[i]);
            else
                if(st.empty())
                return 0;

                else if(str[i]==')'){
                if(st.top() !='(')
                return 0;

                else
                   st.pop();
                }

                 else if(str[i]=='}'){
                if(st.top() !='{')
                return 0;

                else
                   st.pop();
            }

            else{
                 if(st.top() !='[')
                return 0;

                else
                   st.pop();
            }
        

        }
  return st.empty();
}



int minimum_required_paranthesis(string str){
    int count=0;
    stack<int>st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        st.push(str[i]);

        else
            {
                if(st.empty())
                count++;

                else
                    st.pop();
            }
    }

    return count + st.size();
}
int main()
{
    string str;
    char ch;
    cin>>str;
    // do{
    //     cout<<"enter 1 to check first paranthesis\n";
    //     cout<<"enter 2 to check second paranthesis\n";
    //     cout<<"enter 3 to exit from programme\n";
    //     cout<<"enter your choice\n";
    //     cin>>ch;
    // switch(ch){
    //     case 1: cout<<check_paranthesis(str);
       
    //     break;

    //      case 2: cout<<check_paranthesis1(str);
        
    //      break;

    //      case 3: cout<<"exiting programme\n";
    //      break;

    //     //  default: cout<<"invalid choice please insert correct input\n";

    // }
    // }while(ch!=3); 

//     return 0;

    cout<< minimum_required_paranthesis(str);
 }