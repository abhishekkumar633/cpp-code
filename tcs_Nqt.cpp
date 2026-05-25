#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<climits>
using namespace std;

int Range_cube_sum(int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++){
        sum += i*i*i;
    }
    return sum;
}
int sumOf10_table(){
    int sum=0;
    for(int i=1;i<=10;i++){
        sum += 10*i;
    }
    return sum;
}

vector<int> find_maxEle_in_contigiousArray(vector<int>arr,int k){
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<=n-k;i++){
        int maxi=arr[i];
        for(int j=i;j<i+k;j++){
            maxi=max(maxi,arr[j]);
        }
        ans.push_back(maxi);    
    }
    return ans;
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
     if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int bitwise_OR_operation(vector<int>arr){
    unordered_set<int> prev;
    unordered_set<int> result;
    for(int x : arr){
        unordered_set<int> curr;
        curr.insert(x);
        for(int P : prev){
            curr.insert(P|x);
        }
        for(int C : curr){
            result.insert(C);
        }
        prev=move(curr);
    }
    return result.size();

}

vector<int> majority_element(vector<int>arr){
   unordered_map<int,int>freq;
   vector<int>result;
   int n=arr.size();
   for(int num : arr){
    freq[num]++;
   }
   for(auto &num : freq){
    if(num.second >n/2 )
        result.push_back(num.first);
   }
   return result;
}

vector<int> majority_element2(vector<int>arr){
   unordered_map<int,int>freq;
   vector<int>result;
   int n=arr.size();
   for(int num : arr){
    freq[num]++;
   }
   for(int num : arr){
    if(freq[num] >=n/2 )
       result.push_back(num);   
   }
   return result;
}

// want to return average grade of only female student by considering ascii value of grade
struct student{
    string name;
    char grade;
    string gender;
    int age;
};
void print_age_greaterThan20(student s[],int n){
    for(int i=0;i<n;i++){
        if(s[i].age>20){
            cout<<"student name is:"<<s[i].name<<endl<<"age is :"<<s[i].age<<endl;
        }
    }
}
double average_gradeFemale_ascii_value(student s[],int n){
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        if(s[i].gender=="female"){
            sum += int(s[i].grade);
            count++;
        }
    }
    if(count==0){
        return 0;
    }
    return double((sum)/count);
}

void bubble_sort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

void printArray(vector<int>&arr,int n){
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}

int missing_number(vector<int>arr,int n){
    vector<int>freq(n+1,0);
    for(int num : arr){
       freq[num]++;
    }        
   for(int i=1;i<=n;i++){
        if(freq[i]==0)
            return i;
   }      
}

int greater_prior_element(vector<int>arr){           
    int n=arr.size(),ans,count=1;
    int ans=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>ans){
            count++;
        }
        else{
            ans=arr[i];
        }
    }
    return count;
}
int main(){
    student students[3]={
        {"AAA",'A',"female",21},
        {"BBB",'B',"male",22},
        {"CCC",'C',"female",24}
    };
    // print_age_greaterThan20(students,3);
    // cout<< average_gradeFemale_ascii_value(students,3);
    int start=4,end=9;
    // vector<int>arr={2,4,2,4,2,4};
    // vector<int>ans= majority_element(arr);
    // for(int X : ans){
    //     cout<<X<<" ";
    // }

    vector<int>arr={3,2,1,4,6,2,6,3};
    bubble_sort(arr,8);
    printArray(arr,8);
    //cout<<Range_cube_sum(start,end);
   // cout<<sumOf10_table();

   // vector<int>arr={2,4,7,1,6,3};
    // vector<int>arr={1,2,4};
    // cout<< bitwise_OR_operation(arr);
    //int k=3;
    // vector<int> result = find_maxEle_in_contigiousArray(arr, 3);
    // for(int x:result){
    //     cout<<x<<" ";
    // }
    // int n=5;
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     // cout<<fibonacci(i)<<" ";
    //         sum += fibonacci(i);
    // }
    // cout<<sum;
    
}