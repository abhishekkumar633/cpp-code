#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter no of pairs:"<<endl;
    cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    //sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-i-1;j++){
            if(arr[j].first > arr[j+1].first){
                swap(arr[j],arr[j+1]);
            } 
                 else if( arr[j].first == arr[j+1].first  && arr[j].second > arr[j+1].second ){
                    swap(arr[j],arr[j+1]);
            }
        }
    }
    for(auto it:arr){
        cout<<it.first<<" "<<it.second;
    }
return 0;
}