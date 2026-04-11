#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#include<unordered_set>
#include<unordered_map>
using namespace std;
vector<int> separate_0_atThe_last(vector<int>arr,int n){
    int indx=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            arr[indx]=arr[i];
            indx++; 
        }
    }
    for(int i=indx;i<n;i++){
       arr[i]=0;
    }
    return arr;
}   
vector<int> separate_0_atEnd(vector<int>arr,int n){
        int start=0,end=n-1;
       while(start<end){
            if(arr[start]==0){
               swap(arr[start],arr[end]);
                end--;               
            }
            else{
                start++;
            }
       }
       return arr;
}

int count_sunday(string day,int no_of_days){
    vector<string>days={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int start_day_indx=find(days.begin(),days.end(),day)-days.begin();
    int count=0;
    for(int i=0;i<no_of_days;i++){
       int curr_day=(start_day_indx+i)%7;
        if(days[curr_day] == "Sunday"){
            count++;
        }
    }
    return count;
}

void bubble_sort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }  
}
 void print_array(vector<int>&arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }

int count_greater_prior_ele(vector<int>arr,int n){
    int maxi=arr[0],count=1;
    for(int i=1;i<n;i++){      
        if(arr[i]>maxi){
            count++;
            maxi=arr[i];
        }
    }
    return count;
}

int multi(int num){ 
    int rem,prod=1;
    while(num>0){
        rem=num%10;
        prod=prod*rem;
        num = num / 10;
    }
    return prod;
}

int maxim_color(string str,int L){
    
    int maxi=INT_MIN;
    for(int i=0;i<str.size();i+=L){
        int count=0;
        for(int j=i;j<=i+L;j++){
            if(str[j]=='a'){
                count++;
            }
            maxi=max(count,maxi);
        }
    }
    return maxi;
}

int pairsSum_divisibleBy_2(vector<int>arr){
    int even=0,odd=0;
    for(int num:arr){
        if(num%2==0){
            even++;
        }
        else{
            odd++;
        }
    }

    long long pairs= (1LL*even*(even-1))/2+(1LL*odd*(odd-1))/2;
    return pairs;
     
}
int minimum_numberSum_divisibleBy_3(string str){
    
}
int main(){
     vector<int>arr={2,4,6,0,0,2,0,5,0};
    vector<int>ans= separate_0_atEnd(arr,9);
    // vector<int>ans=separate_0_atThe_last(arr,arr.size());
    for(int num : ans){
        cout<<num<<" ";
    }
    // vector<int>arr={1,0,2,0,1,0,2};
    // bubble_sort(arr,arr.size());
    // print_array(arr,arr.size());
    // vector<int>arr={7,4,8,2,9};
    // cout<< count_greater_prior_ele(arr,arr.size());
    //cout<<multi(5244);

    //cout<<count_sunday("Monday",25);
    // cout<<"number of test cases:"<<endl;
    // int T;
    // cin>>T;
    // while(T--){
    //     int n;
    //     cout<<"enter the size of array"<<" ";
    //     cin>>n;
    //     vector<int>arr(n);
    //     cout<<"enter elements :"<<" ";
    //     for(int i=0;i<n;i++)
    //         cin>>arr[i];
        
    //     cout<<pairsSum_divisibleBy_2(arr)<<endl;
    // }
}