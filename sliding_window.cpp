#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include<unordered_set>
using namespace std;
int count_twoTypes_fruit(vector<int>arr){
    int right=0,left=0,max_val=0;
    unordered_map<int,int>mp;
    for(right=0;right<arr.size();right++){
        mp[arr[right]]++;
        while(mp.size()>2){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        max_val=max(max_val,right-left+1);
    }
    return max_val;
}
int longest_subarray_unique_ele(vector<int>arr){
    unordered_map<int,int>mp;
    int right=0,left=0,max_val=0;
    for(right=0;right<arr.size();right++){
        mp[arr[right]]++;
        while(mp[arr[right]]>1){
            mp[arr[left]]--;
            left++;
        }
        max_val=max(max_val,right-left+1);
    }
    return max_val;
}

int target_sum_subarray(vector<int>arr,int target){
    int sum=0,min_len=INT_MAX,left=0;
    for(int right=0;right<arr.size();right++){
        sum += arr[right];
        while(sum >= target){
            min_len=min(min_len,right-left+1);
            sum -= arr[left];
            left++;
        }
    }
    return (min_len == INT_MAX) ? 0 :min_len;
}
int at_most_k(vector<int>arr,int k){    // count subarray whose element repetition should be max 2 in unordered map if exceeds then start contacting left pointer from left side w
    unordered_map<int,int>mp;
    int left=0,count=0;
    for(int right=0;right<arr.size();right++){
        mp[arr[right]]++;
        while(mp[arr[right]]>k){
            mp[arr[left]]--;
             if(mp[arr[left]] == 0) {
                mp.erase(arr[left]);
            }
            left++;
        }
        count += right-left+1;
    }
    return count;
}

int count_exactly_k_ele_subarray(vector<int>arr,int k){
    return at_most_k(arr,k)-at_most_k(arr,k-1);
}
vector<int> return_maximum_ele_INEveryWindowSize_k(vector<int>arr,int k){
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        int max_val=INT_MIN;
        for(int j=i;j<i+k;j++){
            max_val=max(max_val,arr[j]);
        }
            ans.push_back(max_val);
    }
    return ans;
}

int character_replacement(string str,int k){
    vector<int>freq(26,0);
    int right=0,max_len=0,max_freq=0,left=0;
    while(right<str.size()){
        freq[str[right]-'A']++;
        max_freq=max(max_freq,freq[str[right]-'A']);
        while((right-left+1)-max_freq>k){
            freq[str[left]-'A']--;
            left++;
        }
        max_len=max(max_len,right-left+1);
        right++;
    }
    return max_len;
}

int length_of_longest_substring_without_repeating_character(string str){
    unordered_map<char,int>mp;
    int right=0,left=0,max_val=0;
    for(right=0;right<str.size();right++){
        mp[str[right]]++;
        while(mp[str[right]]>1){
            mp[str[left]]--;
            left++;
        }
        max_val=max(max_val,right-left+1);
    }
    return max_val;
}
int max_sum_subarray_windowSize_K(vector<int>arr,int k){
    int left=0,window_sum=0;
    for(int right=0;right<k;right++){
        window_sum += arr[right];
    }
    int max_val=window_sum;
    for(int right=k;right<arr.size();right++){
        window_sum += arr[right];
        window_sum -= arr[left];
        left++;
        max_val = max(max_val,window_sum);
    }
    return max_val;
}
vector<int> first_negativeEle_of_every_window_size_k(vector<int>arr,int k){
    queue<int>q;
    int left=0;
    vector<int>ans;
    for(int right=0;right<arr.size();right++){
        if(arr[right]<0){
            q.push(right);
        }
        if(right-left+1==k){
            if(q.size()>0){
               ans.push_back(arr[q.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        if(q.size()>0 && q.front()==left){
            q.pop();
        }

        left++;
    }
    return ans;

}
int sub_arraySum_equals_K(vector<int>arr,int k){  // count no of subarray whose sum is equals to k;
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0,count=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];              // prefix sum;
        if(mp.find(sum-k) != mp.end()){   // whether sum-k present in map or not 
            count += mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}

int longest_subarraySum_equals_k(vector<int>arr,int k){
    unordered_map<int,int>mp;
    int max_len=0,sum=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum==k)  max_len=i+1;
        if(mp.find(sum-k) != mp.end()){
            max_len=max(max_len,i-mp[sum-k]);
        }
        if(mp.find(sum-k) == mp.end()){
            mp[sum]=i;
        }
    }
    return max_len;   
}
int longest_consecutive(vector<int>arr){
    int longest=0, current_num,count;
    unordered_set<int>st(arr.begin(),arr.end());
    for(int num : st){
        if(st.find(num-1)==st.end()){ // here if the value is present in the set then skip otherwise move inside
              current_num=num;
              count=1;
        }
        while(st.find(current_num+1) != st.end()){
            current_num++;
            count++;
        }
        longest=max(longest,count);
       
    }
    return longest;

}
int main(){
   // vector<int>ans={1,2,3,2,2};
   // cout<<count_twoTypes_fruit(ans);
    // vector<int>arr={1,2,1,3,4,5,2,3};
    // cout<< longest_subarray_unique_ele(arr);
    // vector<int>arr1={2,3,1,2,4,3};
    // cout<< target_sum_subarray(arr1,7);
    //  vector<int>arr2={1,3,-1,-3,5,3,6,7};
    // vector<int>ans=return_maximum_ele_INEveryWindowSize_k(arr2,3);
    // for(int x:ans){
    //     cout<<x<<" ";
    // }
    // string str="AAABBA";
    // cout<< character_replacement(str,2);
    // string str="ababcdbb";
    // cout<<length_of_longest_substring_without_repeating_character(str);
    // vector<int>arr={2,1,5,1,3,2};

    // cout<<max_sum_subarray(arr,3);
    // vector<int>arr={1,2,3};
    // cout<< sub_arraySum_equals_K(arr,3);
    vector<int>arr={1,-1,5,-2,3};
    cout<<longest_subarraySum_equals_k(arr,3);
}