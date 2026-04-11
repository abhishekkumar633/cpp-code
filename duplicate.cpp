#include<iostream>
#include<vector>
using namespace std;
vector<int> duplicate_ele(vector<int>arr,int n){
    int count=0;
    vector<int>freq(n,0);
    vector<int>ans;
    for(int num:arr){
        freq[num]++;
    }
    for(int i=0;i<freq.size();i++){
        if(freq[i]>1) {
            ans.push_back(i);
    }
}
 return ans;
}
int main(){
    vector<int>arr={2,3,4,5,6,6,7,7,8,9,9};
    vector<int>ans=duplicate_ele(arr,11);
    for(int num:ans){
        cout<<num<<" ";
    }
    vector<char> keys = {'A','Y','B','T','H','C'};
     vector<int> arr = {28,25,31,31,3,5};
     for(char key:keys){
        int shifts=key-'A'+1;
        for(int num : arr){
            int val=num-shifts;
            if(val>=1 && val <=26){
                char ch = 'A'+val-1;
                cout<<ch<<" ";
            }
        }
     }
}