#include<iostream>
using namespace std;
int main()
{
    // int a[5];
    // int *c;
    // cout<<sizeof(a)<<" "<<sizeof(c);

//    char b[]="xyz";
//    char *c=&b[0];
//    cout<<c<<endl;

//char s;
// char s[]="hello";
// char *p=&s[1];
// //for(int i=0;i<s.size())
// cout<<s[0]<<" "<<p;

// string str;
// cout<<"enter string\n";
// cin>>str;

// for(int i=0;i<str.size();i++)
// {
//     cout<<str[i];
// }

int a[]={1,2,3,4};
//int *p=&a[0];
cout<<*(a+1)<<endl;
cout<<sizeof(a)<<endl;
    
}
