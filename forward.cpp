#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
using namespace std;

int remove_duplicate(vector<int>&arr){
    int k=0;
    for(int i=1;i<arr.size();i++){
        if(arr[k] != arr[i]){
            k++;
            arr[k]=arr[i];
        }
    }
    return k+1;
}
// remove duplicate elements in an unsorted array
vector<int> remove_duplicate_ele(vector<int>arr1){
    unordered_set<int>st;
    vector<int>result;
    for(int x:arr1){
        if(st.find(x)==st.end()){
            st.insert(x);
            result.push_back(x);
        }
    }
    return result;
}
vector<int> insertELE_at_starting(vector<int>&arr,int val){
    arr.push_back(0); // first increase the size
    for(int i=arr.size();i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=val;
    return arr;
}
vector<int> insert_at_end(vector<int>&arr,int val){
    arr.insert(arr.end(),val);
    return arr;
}

vector<int> insertELE_at_certain_index(vector<int>&arr,int index,int val){
    arr.push_back(0); // first increase the size
    for(int i=arr.size();i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=val;
    return arr;
}

vector<int> non_repeating_ele(vector<int>arr,int n){
    int max_ele=*max_element(arr.begin(),arr.end());
    vector<int>freq(max_ele+1,0);
    vector<int>ans;
    for(int num : arr){
        freq[num]++;
    }
    for(int i=0;i<freq.size();i++){
       if(freq[i]==1)
        ans.push_back(i);
    }
    return ans;
}
vector<int> repeating_ele(vector<int>arr){
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int num:arr){
        mp[num]++;
    }
    for(auto it :mp){
        if(it.second>1){
            ans.push_back(it.first);
        }
    }
    return ans;

}
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
         return a.first < b.first;
    }
       
    return a.second > b.second;
}
int gcd(int a,int b){
    return __gcd(a,b);
}
int main(){
    cout<<gcd(5,17);
    // vector<int>arr={1,1,2,2,3,3,4,4,5};
    // int k=remove_duplicate(arr);
    // for(int i=0;i<k;i++){
    //     cout<<arr[i]<<" ";
    // }

   // vector<int>arr1={2,3,1,9,3,1,3,9};
    // vector<int>result=remove_duplicate_ele(arr1);
    // vector<int>result1= insertELE_at_starting(arr1,20);
    // for(int num:result1){
    //     cout<<num<<" ";
    // }
    // vector<int>result3=insert_at_end(arr1,100);
    //  for(int num:result3){
    //     cout<<num<<" ";
    // }

    // vector<int>result3=insertELE_at_certain_index(arr1,5,500);
    //  for(int num:result3){
    //     cout<<num<<" ";
    // }
//     vector<int>arr={1,1,2,3,4,4,5,2,10,20};
//    /// vector<int>ans= non_repeating_ele(arr,10);
//     vector<int>ans=repeating_ele(arr);
//     for(int num : ans){
//         cout<<num<<" ";
//     }
   vector<int>arr={2,2,2,1,1,3,3,4};
    unordered_map<int,int>mp;
    for(int num:arr){
        mp[num]++;
    }
    vector<pair<int,int>>freq;
    for(auto it :mp){
        freq.push_back({it.first,it.second});
    }
    sort(freq.begin(),freq.end(),cmp);
    for(auto p : freq){
        for(int i=0;i<p.second;i++){
            cout<<p.first<<" ";
        }
    }
}
