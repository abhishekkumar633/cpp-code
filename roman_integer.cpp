#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 int num(char c)
    {
        if(c=='I')
        return 1;

       else if(c=='V')
        return 5;

        else if(c=='X')
        return 10;

       else if(c=='L')
        return 50;

       else if(c=='C')
        return 100;

       else if(c=='D')
        return 500;

    else 
        return 1000;
       
    }
    
int roman_to_integer(string str){
    int index=0,sum=0;
   
    while(index < str.size()-1){
        if(num(str[index])<num(str[index+1])){
            sum -= num(str[index]);
        }

            else
                 {
                    sum += num(str[index]);
                 }
                 index++;
        
    }

    sum += num(str[index]); // used for adding last character bcz we didnt use during while loop
    return sum;
}
int main()
{
    string str;
    cout<<"enter string\n";
    getline(cin,str);

    cout<<"output is\n"<<roman_to_integer(str);
}