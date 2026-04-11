#include<iostream>
#include<vector>
using namespace std;
bool unique_element(int arr[],int n){
    vector<int>freq(5,0);
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<freq.size();i++)
 {
    if(freq[i]>1)
     return true;
 }

 return false;

}

bool check_anagram(string str1,string str2){
   if(str1.size() != str2.size())
   return false;
    vector<int>freq(26,0);
    for(int i=0;i<str1.size();i++)
    {
        freq[str1[i]-'a']++;
        freq[str2[i]-'a']--;
    }

    for(int i=0;i<freq.size();i++)
    {
        if(freq[i]>0)
        return 0;
    }

    return 1;
}

std::pair<int, int> two_sum_indices(int arr[],int n,int target){
    int start=0,end=n-1;
    while(start<end)
    {
        if(arr[start]+arr[end]==target)
        {
            return {start,end};
        }
        else if(arr[start]+arr[end]<target)
           start++;
           else
            end--;
    }

           return {-1,-1};
}

int main(){
     int arr[]={1,2,3,4,5};
    // cout<<unique_element(arr,5);

    string str1 = "cat";
    string str2 = "acc";

    cout<<check_anagram(str1,str2);
    int index1, index2;

    //two_sum_indices(arr, 5, 9, &index1, &index2);

   



}
