#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
using namespace std;
int gcd(int a,int b){
    return __gcd(a,b);
}

bool IsHarshad_number(int num){
    int ans=num;
    int rem,sum=0;
    while(num>0){
        rem=num%10;
        sum += rem;
        num/=10;
    }
  return ans % sum == 0;
}

int next_harshad_num(int num){
    int seq=num+1;
    while(true){
         if(IsHarshad_number(seq)){
            return seq;
       }
       seq++;
    } 
}

int next_Harshad_number(int num){
   int seq=num+1;
    while(true){
        int rem,sum=0;
        int temp=seq;
        while(temp>0){
            rem=temp%10;
            sum += rem;
            temp/=10;
    }
    if(seq % sum == 0){
       return seq;
    }
         seq++;
    }
}

bool isAutomorphic(int num){
    int temp=num;
    int result=num*num;
    while(temp > 0){
        if(result % 10 != temp % 10){
            return false;
        }
        temp /= 10;
        result /= 10;
    }
    return true;
}

vector<int> replace_with_rank(vector<int>&arr){
    vector<int>temp=arr;
    unordered_map<int,int>rank;
    sort(temp.begin(),temp.end());

    int r=1;
    for(int i=0;i<temp.size();i++){
        if(rank.find(temp[i])==rank.end()){
            rank[temp[i]]=r;
            r++;
        }
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=rank[arr[i]];
    }
    return arr;
}

bool isAbundant_number(int num){
    int sum=0;
    for(int i=1;i<num;i++){
        if(num % i == 0){
            sum += i;
        }
    }
    if(sum>num){
        return 1;
    }
    else
        return 0;
}

int digit_product(int num){
    int ans=num,rem,product=1;
    while(ans>0){
        rem=ans%10;
        product *= rem;
        ans /= 10;
    }

    return product;
}

int max_a_substring(string str,int L){
    int maxA=0;
    for(int i=0;i<str.size();i+=L){
        string temp=str.substr(i,L);
        int countA=0;
        for(char c : temp){
            if(c == 'a')
                countA++;
        }
        maxA=max(countA,maxA);
    }
    return maxA;
}
int main(){
    // cout<<gcd(5,15);
     // cout<<IsHarshad_number(400);
      int n=20;

    // for(int i=1;i<=n;i++){
    //     if(IsHarshad_number(i)){
    //         cout<<i<<" ";
    //     }
    // }

   // cout<<next_Harshad_number(19);
    //cout<<next_Harshad_number(100);
    //cout<<isAutomorphic(20);
//     vector<int>arr={20,10,10,20,30,5,6,7,1};
//    // vector<int>ans=replace_with_rank(arr);
//     for(int x:ans){
//         cout<<x<<" ";
//     }

   // cout<< isAbundant_number(20);
   // cout<<digit_product(5244);
    string str="abbbaabbbaaaa";
    cout<<max_a_substring(str,5);
}