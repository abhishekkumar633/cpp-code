#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int perfect_square(int n){
    if(n<0)  return false;
    int root= sqrt(n);
    return root * root == n;
}

// gcd of two number
int gcdOfTwo_number(int a,int b){
    if(b==0){
        return a;
    } else{
            return __gcd(a,b);
    }

}
int sumOfDigit(int n){
    int sum=0,rem,qui;
    while(n>0){
        rem=n%10;
        sum+= rem;
        n=n/10;
    }
    return sum;

}
int reverse(int n){
    int rem,rev=0;
    while(n>0){
        rem = n % 10;
        rev = rev * 10 +rem;
        n = n/10;

    }
    return rev;
}

int factor(int num){
    vector<int>fact;
    int sum=0;
    for(int i=1;i<=num;i++){
        if(num % i ==0){
            fact.push_back(i);
             sum += i;
        }
    }
    // this is in another way;
    // for(int i=0;i<fact.size();i++){
    //    sum += fact[i];
    // }
    return sum;
    
}
int max_factor(int num){
    vector<int>fact;
    for(int i=1;i<=num;i++){
        if(num % i ==0){
            fact.push_back(i);
        }
    }
    int maxi=INT_MIN,ans;
    for(int i=0;i<fact.size();i++){
        maxi=max(maxi,fact[i]);
        ans=maxi;
    }
    return ans;
}
bool armstrong_number(int num){
    int count=0, temp = num,original_number=num;
    while(temp>0){
        temp = temp / 10;
        count++;
    }
    int sum=0;
    temp=num;
     while(temp >0){
            int digit = temp % 10;    
              sum += pow(digit,count);    
              temp = temp/10; 

     }  
     return original_number==sum;
}
bool IsPalindrome(int sum){
    int original=sum,num=sum;
    int rev=0;
    while(num>0){
        int rem=num%10;
        rev=rev*10+rem;
        num /=10;
    }
   return original == rev;
}


bool sum(int a,int b){
    int sum = a+b;
   return IsPalindrome(sum);
}
int first_occurrence(vector<int>arr,int target){
    int start=0,end=arr.size()-1,result;
    while(start<=end){
        int mid=start +(end-start)/2;
        if(arr[mid]==target){
            result=mid;
            end=mid-1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end = mid -1;
        }
    }
    return result;
}
int last_occurrence(vector<int>arr,int target){
    int start=0,end=arr.size()-1,ans;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==target){
             ans= mid;
            start = mid +1;
        }
            else if(arr[mid]<target){
                start = mid +1;
            }
            else{
                end = mid-1;
            }
    }
    return ans;
}

pair<int,int> first_and_last_occurrence(const vector<int>&arr,int target){
        return {first_occurrence(arr,target),last_occurrence(arr,target)};
}

vector<int> Next_greater_element(vector<int>arr,int n){
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}
// stack problem
vector<int> Next_greater_element1(vector<int>arr,int n){
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

vector<int> Next_smaller_element1(vector<int>arr,int n){
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

// stock span problem
vector<int> stock_span_problem(vector<int>price,int n){
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && price[i] > price[st.top()]){
                ans[st.top()]=st.top()-i;
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

// reverse first k element of a queue
void Reverse_first_K_element(queue<int>q,int k){
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    int n=q.size();
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
}

// reversing of a queue
queue<int> reverse(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

// maximum element in a queue
int maximum_element(queue<int>&q){
    int ans=INT_MIN,result,n = q.size();;
    for(int i=0;i<n;i++){
        ans=max(ans,q.front());
        q.pop();
        
    }
    return ans;
}

int maximum_element_stack(stack<int>&st){
    int ans=st.top();
    st.pop();
    while(!st.empty()){
        ans=max(ans,st.top());
        st.pop();
    }
    return ans;
}

void Generate_binary_number(int n){
    queue<string>q;
    q.push("1");
    for(int i=1;i<=n;i++){
        string s = q.front();
        q.pop();
        cout<<s<<" ";
        q.push(s+"0");
        q.push(s+"1");
    }
}

int gcd(int a,int b){
    if(b==0)  return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    // return a*b/gcd(a,b);
    if(a==0 || b==0)  return 0;
    return (a / gcd(a, b)) * b; 
}

void print_k_window_element(vector<int>&arr,int k){
    queue<int>q;
    int n=arr.size();
    for(int i=0;i<n;i++){
        q.push(arr[i]);
        if(q.size()==k){
            queue<int>temp=q;
            while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
        q.pop();
    }
   
    }
}

int main(){
    vector<int>arr={2,3,1,6,7,89};
    print_k_window_element(arr,4);
   /// cout<<LCM(12,18);
    // vector<int>arr={8,6,4,7,4,9,10,8,12};
    //  int a = 12, b = 18;
    // cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
    // cout << "LCM of " << a << " and " << b << " = " << lcm(a, b) << endl;
   // vector<int>ans= Next_greater_element1(arr,9);
    // vector<int>ans= Next_smaller_element1(arr,9);
    // for(int num : ans){
    //     cout<<num<<" ";
    // }
    //  queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // queue<int> q;
    // q.push(3);
    // q.push(7);
    // q.push(1);
    // q.push(9);
    // q.push(5);

    // queue<int>ans=reverse(q);
    // while(!ans.empty()){
    //     cout<<ans.front()<<" ";
    //     ans.pop();
    // }

    //  stack<int> st;
    // st.push(3);
    // st.push(7);
    // st.push(1);
    // st.push(9);
    // st.push(5);

   // cout<<maximum_element_stack(st);
//    cout<<"binary numbers are :"<<endl;
//     Generate_binary_number(10);

    // int k = 3;
    //  Reverse_first_K_element(q, k);

    // while (!q.empty()) {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
   // cout<<maximum_element(q);
   //cout<<perfect_square(16);
 //  cout<<gcdOfTwo_number(18,48);
   //cout<<sumOfDigit(384);
   //cout<< reverse(1234678);
  // cout<<factor(16);
//    int sum=0;
//    for(int a:ans){    
//     cout<<"sum of factor is :"<<sum += a;
//    }

    //cout<< max_factor(50);
   // cout<<armstrong_number(9474);
    //cout<<sum(22,22);
    // vector<int>arr={2,3,3,3,4};
    // pair<int,int>ans=first_and_last_occurrence(arr,3);
    // cout<<"first  occurrence element is at index:"<<ans.first<<endl;
    // cout<<"last occurrence element is at index:"<<ans.second<<endl;
}