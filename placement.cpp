#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int maximum_sum_subarray(const vector<int>&arr,int n){
    int maxi=INT_MIN,prefix=0;
    for(int i=0;i<arr.size();i++){
        prefix += arr[i];
        maxi=max(maxi,prefix);
        if(prefix<0)
        prefix=0;
    }
    return maxi;
}

int maximum_product_subArray(const vector<int>&arr,int n){
    int ans=INT_MIN,prefix=1,suffix=1;
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
       
            prefix *= arr[i];
            suffix *= arr[n-i-1];
            ans = max(ans,max(prefix,suffix));
        
    }
    return ans;
}

int maximum_element(vector<int>arr){
    
}
int maximum_diff_twoEle(vector<int>arr,int n){
    int ans=INT_MIN,suffix;
    int minEle=INT_MAX;
    for(int i=0;i<n;i++){
        ans = max(ans,arr[n-i-1]);
        // ans = max(ans,arr[i]); this one will only run for positive array
        minEle=min(minEle,arr[i]);
    }
    return ans-minEle; 
}
// segregate  0 and 1;
vector<int> segregate0and1(vector<int>arr,int n){
    int start=0,end=arr.size()-1;
    while(start<=end){
        if(arr[start]==0)  start++;
        else if(arr[end]==0){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        else
          end--;
    }
    return arr;
}
// kth missing positive integer
int kthMissingInteger(vector<int>arr,int k){
    int start=0,end=arr.size()-1,missing;
    while(start<=end){
        int mid= start + (end-start)/2;
         missing = arr[mid]-(start+1);
        if(missing<k) start=mid+1;
        else
            end = mid-1;
        
    }
    return k+end+1;
}

int search_sorted_Array(vector<int>arr,int target){
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target) return mid;
        if(arr[start]<=arr[mid]){  // left sorted
            if(target>=arr[start] && target<arr[mid]){
                end=mid - 1;
            }
            else   start=mid+1;
        }
        else{ //right sorted
             if(target>arr[mid] && target<=arr[end]){
               start=mid+1;
            }
            else  
              end=mid - 1;
        }
    }
    return -1;
}

// sort 0s 1s and 2s
vector<int> sort012(vector<int>arr,int n){
    int low=0,mid=0,high=arr.size()-1; // by using three pointer approach!!
    while(mid <= high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)  mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}

pair<int,int> targetSumIndices(vector<int>arr,int target){
    int start=0,end=0,sum=0;
    for(int end=0;end<arr.size()-1;end++){
        sum += arr[end];

        // now use the concept of sliding window
        while(sum>target && start <= end){
            sum -= arr[start];
            start++;
        }
        if(sum==target){
             return {start,end};
        }
       
    }
    return {-1,-1};
}

int kthLargest_element(vector<int>&arr,int k){
    sort(arr.begin(),arr.end(),greater<int>()); // sorting in descending order
    return arr[k-1];
}

int kthSmallest_element(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());  // sorting in ascending order
    return arr[k-1];  
}
vector<int> intersection_of_TwoArray(vector<int>&a,vector<int>&b){
    unordered_set<int> s(a.begin(),a.end());
    vector<int>result;
    for(int num : b){
        if(s.count(num)){
            result.push_back(num);
            s.erase(num);
        }
    }
    return result;
}

// if u also want duplicate element from two intersection of an array
vector<int> intersection_of_TwoArrayDuplicate(vector<int>&a,vector<int>&b){
    unordered_map<int,int>freq;
    vector<int>result;
    for(int num : a){
        freq[num]++;
    }
    for(int num : b){
        if(freq[num]>0){
            result.push_back(num);
            freq[num]--;
        }
    }
    return result;
}
int majority_element(vector<int>arr){
    unordered_map<int,int>freq;
    int n=arr.size();
    for(int num : arr){
        freq[num]++;
    }
    for(auto &num : freq){
        if(num.second>n/2)
        return num.first;

    }
    return -1;
}
vector<int> equilibrium_Indices(vector<int>arr){
    vector<int>ans;
    int Total_sum=0,left_sum=0;
    for(int num : arr){
        Total_sum += num;
    }
    int index=0;
    for(int num : arr){      
       int  right_sum = Total_sum-left_sum-num;
       if(left_sum==right_sum){
            ans.push_back(index);            
       }       
        left_sum += num;
        index++;
    }   
        return  ans;
}

// positive and negative integer alternatively
vector<int> Positive_NegativeAlternatively(vector<int>&arr){
    vector<int>pos,neg;
    for(int num : arr){
        if(num >=0){
            pos.push_back(num);
        }
        else neg.push_back(num);
    }
    int i=0,n=0,p=0;
    bool turnPos=true;
    while(p<pos.size() && n < neg.size()){
        if(turnPos){
            arr[i]=pos[p];
            p++;
            i++;
        }
        else{
            arr[i]=neg[n];
            i++;
            n++;
        }
        turnPos = !turnPos;
    }
    while(p<pos.size()){
        arr[i]=pos[p];
        i++;
        p++;
    }
     while(n<neg.size()){
        arr[i]=neg[n];
        i++;
        n++;
    }
    return arr;
}

bool IsShuffle(string A,string B,string C){
    if(C.length() != A.length()+B.length())  return false;
    int i=0,j=0,k=0; //by using concept of two pointer

    while(k<C.length()){
        if(i<A.length() && A[i]==C[k]){
            i++;
        }
        else if(j<B.length() && B[j]==C[k]){
            j++;
        }
        else{
            return false;
        }
        k++;
    }
    return (i ==A.length() && j == B.length());
}
//minimum window substring problem
string minimum_window_substring(string s,string t){
    int left=0,right=0,min_length=INT_MAX,start=0;
    unordered_map<char,int>mapT;
    for(char c : t){
        mapT[c]++;
    }
    int have=0,need=mapT.size();
    unordered_map<char,int>window;
    while(right<s.size()){  // Here we are expanding the window...
        char c = s[right];
        window[c]++;
        if(mapT.count(c) && window[c]==mapT[c]){
            have++;
        }
    
    while(have == need){
        // updating the window size;
        if((right-left+1)<min_length){
            min_length=right-left+1;
            start=left;
        }// reducing window size..
        char c = s[left];
        window[c]--;
        if(mapT.count(c) && window[c] < mapT[c]){
            have--;
        }
        left++;
    }
    right++;
    }
    return  (min_length == INT_MAX) ? "" : s.substr(start, min_length);
}
int LongestSubstring_without_Duplicate(string str){
    unordered_set<char>seen;
    int left=0,right=0,max_len=0;
    while(right < str.size()){
        if(seen.find(str[right])==seen.end()){
            seen.insert(str[right]);
            max_len=max(max_len,(left-right+1));
            right++;
        }
        else{
            seen.erase(str[left]);
            left++;
        }      
    }
    return max_len;

}

//zero sumarray subarray by using concept of sliding window
int zero_sum_subarray(vector<int>&arr,int n){
    int total=0,prefix_sum=0;
    unordered_map<int,int>map;
    map[0]=1;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        if(map.count(prefix_sum)){
            total += map[prefix_sum];
            map[prefix_sum]++;
        }
        else{
            map[prefix_sum]=1;
        }
    }
    return total;
}

// sub array sum equals k by using concept of sliding window
int sub_arraySumEquals_k(vector<int>arr,int n,int k){
    unordered_map<int,int>map;
    int prefix_sum=0,total=0;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        if(map.count(prefix_sum-k)){
            total += map[prefix_sum-k];
            map[prefix_sum]++;
        }
        else{
            map[prefix_sum]++;
        }
    }    return total;
}

// Maximum Sum Subarray 
int maximum_sumSubarraySize_k(vector<int>arr,int n,int k){
    int maxi=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            sum += arr[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

//sub array sum divisible by k
int subArraySum_divisibleBy_k(vector<int>arr,int n,int k){
    unordered_map<int,int>map;
    int total=0,prefix_sum=0,result;
    map[0]=1;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        result=prefix_sum%k;
        if(result<0){
            result=result+k;
        }
        if(map.count(result)){
            total += map[result];
            map[result]++;
        }
        else{
            map[result]=1;
        }
    }
    return total;
}
int subArrayProduct_lessThan_k(vector<int>arr,int n,int k){
    int left=0,right=0,total=0;
    long long product=1;
    while(right<n){
        
        product *= arr[right]; // here expanding the size of window
        while(product>=k&& left<=right){  //here decreasing the size of window..
            product/=arr[left];
            left++;
        }
            total +=right-left+1;
            right++;
    
    }
    return total;
}
int minimumSizeSubarray_sum_greaterEqual_k(vector<int>arr,int n,int k){
    int min_size=INT_MAX;
    int left=0,right=0,sum=0,total=0;
    while(right<n){
        sum += arr[right];
        while(sum >= k && left<=right){
            total = right-left+1;
            min_size=min(min_size,total);
            sum -= arr[left];
            left++;          
        }
        right++;
    }
    return min_size;  
}
int longestSubarrayAtmos_kFreq(vector<int>arr,int n,int k){
    unordered_map<int,int>count;
    int left=0,right=0,len=INT_MIN;
    while(right<n){
        count[arr[right]]++; // expanding
        while(count[arr[right]]>k){ //shrinking
            count[arr[left]]--;
            left++;
        }
        len=max(len,right-left+1);
        right++;
    }
    return len;
}

long long countSubarrays(vector<int>& nums, int k) {
        int left=0,right=0,max_ele=INT_MIN,count=0;
        long long total=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            max_ele=max(max_ele,nums[i]);
        }

        while(right<n){
            if(nums[right]==max_ele)
                count++;
                while(count==k && left<=right){
                    total += n-right;
                    if(nums[left] == max_ele){
                        count--;                   
                    }
                     left++;
                }
            
            right++;
        }
        return total;
    }
void generate_subarray(vector<int>arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"{";
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<"}";
            cout<<endl;
        }
    }   
}
int main(){
     vector<int>arr={1,2,20,10};
    cout<<maximum_diff_twoEle(arr,4);
   
    //generate_subarray(arr,arr.size());
    // vector<int> arr = {2, 3, -4, -9, -1, -7, 1, -5, -6};
    // vector<int>arr={6,-1,3,4,-2,2,4,6,-12,-2};
   
   // cout<<zero_sum_subarray(arr,arr.size());
   // cout<<sub_arraySumEquals_k(arr,arr.size(),6);

   // vector<int>arr={3,5,6,3,9,4,6,9};
    // vector<int>arr={2,3,-8,-3,11,4,8,6,9,4};
    // int n=8;
    // vector<int> arr = {4, 5, 0, -2, -3, 1};
    // int k = 5;
    // cout<<subArraySum_divisibleBy_k(arr,arr.size(),k);
    // vector<int>arr={2,5,10,8,100,1000,5,15};
    // cout<<subArrayProduct_lessThan_k(arr,arr.size(),999);
    // vector<int> ans= Positive_NegativeAlternatively(arr);
    // for(int num : ans){
    //     cout<<num<<" ";
    // }
    //  string A = "abc", B = "def", C = "adbcef";
//     vector<int> arr = {2,3,1,2,4,3};
// int k = 7;
// cout << minimumSizeSubarray_sum_greaterEqual_k(arr, arr.size(), k);

    // if (IsShuffle(A, B, C)) {
    //     cout << C << " is a valid shuffle of " << A << " and " << B << endl;
    // } else {
    //     cout << C << " is NOT a valid shuffle of " << A << " and " << B << endl;
    // }
   // IsShuffle("abc","def","adbcef");
//    vector<int>arr={2,8,1,4,3,3,3,3};
//    cout<< majority_element(arr);
//    vector<int>arr={-7, 1, 5, 2, -4, 3, 0};
//    vector<int>ans= equilibrium_Indices(arr);
//    for(int num : ans){
//     cout<<num<<" ";
//    }
//    vector<int>b={5,8,1,3,3};
//    vector<int>ans=intersection_of_TwoArrayDuplicate(a,b);
//    for(int num : ans){
//     cout<<num<<" ";
//    }
    //  vector<int>arr={1,0,0,1,1,0,0,2,2,0,1};
    //  arr=sort012(arr,arr.size());
    // for(int num :arr){
    //     cout<<num;
    // }
    // vector<int>arr={1,4,20,3,10,5};
    // int k=3;
   // cout<<"kth largest element:"<<" "<<kthLargest_element(arr,k);
   // cout<<"smallest element is :"<<" "<<kthSmallest_element(arr,k);
    // int target=33;
    // auto ans = targetSumIndices(arr,target);
    // if(ans.first != -1){
    //     cout<<"array indices found from :"<<ans.first<<" "<<"to"<<ans.second<<endl;
    // }
    // else
    //   cout << "No subarray found" << endl;
    //  vector<int>arr={2,3,4,7,11};
    //  cout<< kthMissingInteger(arr,5);
    // vector<int>arr1=segregate0and1(arr,arr.size());
    //  for(int num : arr1){
    //     cout<<num;
    //  }
     
   //cout<<maximum_sum_array(arr,arr.size());
   //cout<<maximum_product_subArray(arr,arr.size());
   //cout<<maximum_diff_twoEle(arr,arr.size());
    return 0;
}