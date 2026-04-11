#include<iostream>
#include<unordered_set>
#include<vector>
#include<unordered_map>
using namespace std;
int count_unique_ele(vector<int>arr){
    unordered_set<int>st;
    int count=0;
    for(int val : arr){
        if(st.find(val) == st.end()){
            st.insert(val);
            count++;           
        }
    }
    return count;
}

// vector<int> count_unique_ele1(vector<int>&arr){
//     unordered_set<int>st;
//     int count=0;
//     for(int val : arr){
//         if(st.find(val) == st.end()){
//             st.insert(val);
//             count++;           
//         }
//     }
//     return st;
// }

vector<int> unique_ele(vector<int>arr){
    unordered_map<int,int>mp;
    vector<int>ans;
    int count=0;
    for(int val:arr){
        mp[val]++;
    }
    for(auto  it:mp){
        if(it.second==1){
            ans.push_back(it.first);
            count++;
        }
    }
    return ans;

}
int missing_ele(vector<int>arr,int n){
     long long total_sum= (n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return total_sum-sum;
}

int main(){
    vector<int>arr={2,3,4,4,2,6,7,8,8,10};
   // cout<<count_unique_ele(arr);
   vector<int>arr1={1,2,3,4,6,7};

    // vector<int>ans=count_unique_ele1(arr);
    // for(int x:ans){
    //     cout<<x<<" ";
    // }
   //vector<int>ans=unique_ele(arr);
    //  for(int x:ans){
    //     // cout<<x<<" ";
    // }
    cout<<missing_ele(arr1,7);
}