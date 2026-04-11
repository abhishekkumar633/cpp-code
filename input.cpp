#include<iostream>
#include<vector>
using namespace std;
int main(){
   
    // int arr[20];
    vector<int>ans(5);
   cout<<"enter elements:"<<endl;
    for(int i=0;i<5;i++){
        cin>>ans[i];
    }
    cout<<"elements are:"<<endl;
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }
}