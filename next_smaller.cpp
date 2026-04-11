#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>  next_smaller_element(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&arr[st.top()]>arr[i])
        {
                ans[st.top()]=i;
                st.pop();
        }
         st.push(i);
    }
    return ans;
}
int main()
{
    vector<int>arr={3,1,6,2,8};
   // next_smaller_element(arr);
      vector<int> result = next_smaller_element(arr);

    cout << "Next smaller element indices: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}