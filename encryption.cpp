#include<iostream>
#include<vector>
using namespace std;
vector<int> remove_duplicate_ele(vector<int>arr1,int n){
    int k=0;
    for(int i=1;i<n;i++){
        if(arr1[k]!=arr1[i]){
            k++;
            arr1[k]=arr1[i];
        }
    }
    vector<int>ans;
    for(int i=0;i<k+1;i++){
        ans.push_back(arr1[i]);
    }
    return ans;
}
vector<int> move_zeroTo_end(vector<int>arr,int n){
    
}
int main(){
    vector<int>arr1={1,1,2,3,4,4,5};
    //   vector<char> keys = {'A','Y','B','T','H','C'};
    //  vector<int> arr = {28,25,31,31,3,5};
    //  for(char key:keys){
    //     int shifts=key-'A'+1;
    //     for(int num : arr){
    //         int val=num-shifts;
    //         if(val>=1 && val <=26){
    //             char ch = 'A'+val-1;
    //             cout<<ch<<" ";
    //         }
    //     }
    //  }
    vector<int>ans=remove_duplicate_ele(arr1,7);
    for(int num:ans){
        cout<<num<<" ";
    }

}