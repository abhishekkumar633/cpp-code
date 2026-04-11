#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#include<numeric>
using namespace std;



//Remove duplicate character from string

string remove_duplicate(string str){
    vector<int>freq(26,0);
    string ans="";
    for(char c: str){
        if(freq[c-'a'] == 0)
        ans += c;
        freq[c-'a']=1;
    }
    return ans;

}
//
char nearest_vowel(char ch){
    string vowel="aeiou";
    char nearest = 'a';
    int minDist=INT_MAX;
    for(char v:vowel){
         int abs_dist=abs(ch-v);
         if(abs_dist<minDist){
            minDist=abs_dist;
            nearest=v;
         }
    }
   
    return nearest;
}

string only_vowel(string str){
    string vowel="aeiou";
    for(char &c : str){
       // if(vowel.find(c) == string::npos)
        if(c !='a'&&c !='e'&&c !='i'&&c !='o'&&c !='u')
            c=nearest_vowel(c);
    }
    return str;
}


// problem to find gcd of the given array whose value is 1
bool IsCoprime(int a,int b){
    return __gcd(a,b)==1;
}


// dealership problem

struct Dealership{
    int car;
    int bike;
};
void countTyres(const vector<Dealership>&dealership){
    int total_tyres=0,tyres;
    for(int i=0;i<dealership.size();i++){
        tyres = dealership[i].car * 4 + dealership[i].bike * 2;
        total_tyres += tyres;
        cout<<"dealership"<<i+1<<"has"<<"bike and car"<<tyres<<endl;
    }
    cout<<"total tyres are"<<total_tyres;
}

// find the first non repeating character
char first_non_repeating_character(string str){
    vector<int>freq(26,0);
    for(char c : str){
        freq[c-'a']++;  // count the freq
    }
    for(char c : str){
        if(freq[c-'a']==1){
            return c;
        }
    }
    
}
// duplicate in an array
vector<int> duplicate_element(vector<int>arr){
    int max_value=*max_element(arr.begin(),arr.end());

    vector<int>freq(max_value+1,0);
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<=max_value;i++){
        if(freq[i]>1){
            ans.push_back(i);
        }
    }
    return ans;
}

// merge sort
vector<int> merge_sort(const vector<int>&arr1,const vector<int>&arr2){
   // by using two pointer approach;
    vector<int>ans;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] <= arr2[j]){
             ans.push_back(arr1[i]);
             i++;
        }
       else{
        ans.push_back(arr2[j]);
        j++;
       }
    }
    while(i<arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }
     while(j<arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

// missing number in the array
int missing_number(const vector<int>&arr1,int n){
    int total=n*(n+1)/2;
    int sum=0;
    for(int num : arr1){
        sum += num;
    }
    return total-sum;
}
// lcm of two number

int gcd(int a,int b){
    while(b !=0){
        int temp=b;
        b=a % b;
        a=temp;
    }
    return a;
}
int lcmOfTwoNumber(int a,int b){
     return (a /gcd(a, b)) * b;
}
int main(){
     vector<int>arr1={1,2,4,5,6};
     int n=6;
     cout<<"missing number is :"<<" "<< missing_number(arr1,n);
    //   vector<int>arr2={3,5,6,9,18,22};
    //   vector<int>merged=merge_sort(arr1,arr2);
    //   for(int x : merged){
    //     cout<<x<<" ";
    //   }
    //   cout<<endl;
      
    // int n=arr.size();
    // vector<pair<int,int>>ans;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(IsCoprime(arr[i],arr[j])){
    //             ans.push_back({arr[i],arr[j]});
    //         }
    //     }
    // }mmmmmmmmmmmmnbbbvcdfdza  12we\

    // for(auto x:ans){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    //cout<<remove_duplicate("abhisshekKDD");
    //  int n;
    // vector<Dealership>dealership(n);
 
    // cout<<"enter total no of dealership";
    // cin>>n;
    // cout<<"enter the value of cars and bikes"<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<"dealership"<<" "<<i+1<<"has car & bikes are:";
    //     cin>>dealership[i].car>>dealership[i].bike;
    // }
    // countTyres(dealership);
    
   // cout<<first_non_repeating_character("abbcde");
    //cout<<only_vowel("abcedituo");
}