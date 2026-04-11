#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int Largest_rectangle(vector<int>&height){
    int n=height.size();
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;

    for(int i=0;i<n;i++)
    {
       
        while(!st.empty()&&height[st.top()]>height[i]) 
        {
            right[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
        while(!st.empty())
        {
            right[st.top()]=n;
            st.pop();
        }

    for(int i=n-1;i>=0;i--)
    {
       
        while(!st.empty()&&height[st.top()]>height[i])
        {
            left[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }

     while(!st.empty())
        {
            left[st.top()]=-1;
            st.pop();
        }
    int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,height[i]*(right[i]-left[i]-1));

        }

        return ans;
}
int main()
{
    vector<int>height={2,1,4,8,2,7,1,6};
    cout<<"largest area is :"<<Largest_rectangle(height);
}

