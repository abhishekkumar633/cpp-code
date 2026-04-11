#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<char,int>map;
    map['a']=1;
    map['b']=2;
    map['c']=2;
    map['d']=4;
    for(auto p:map){
        //cout<<"first character "<<p.first<<endl<<"second character"<<p.second<<endl;
         cout << p.first << " -> " << p.second << endl;
    }
}
