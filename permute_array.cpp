#include<iostream>
#include<vector>
using namespace std;
void  permute_array(int arr[],vector<int>&temp,vector<bool>&visited,vector<vector<int>> &ans){

  if(visited.size()==temp.size())
  {
    ans.push_back(temp);
    return;
  }
  for(int i=0;i<visited.size();i++)
  {
    if(visited[i]==0)
    {
        visited[i]=1;
        temp.push_back(arr[i]);
        permute_array(arr,temp,visited,ans);
        visited[i]=0;
        temp.pop_back();
    }
  }
}
int main()
{
    int arr[]={1,4,5};
    vector<int>temp;
    vector<bool>visited(3,0);
    vector<vector<int>> ans;
    permute_array(arr,temp,visited,ans);
    cout<<"permuted result is :\n";
    for(int i=0;i<ans.size();i++){
     for(int j=0;j<ans[i].size();j++)
     cout<<ans[i][j]<<" ";
     cout<<endl;
    }
}
