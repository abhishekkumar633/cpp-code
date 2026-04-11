#include<iostream>
#include<vector>
using namespace std;
bool binarysearch_2d(vector<vector<int>>& mat, int row, int col,int target){
    int start=0,end=(row*col)-1,mid;
    while(start<=end){
        mid=start+end/2;
        int row_index=mid/col;
        int col_index=mid%col;
        if(mat[row_index][col_index]==target)
        return 1;
        else if(mat[row_index][col_index]<target)
        start=mid+1;
        else
        end=mid-1;
    }
    return 0;

}
int main()
{
    int row,col,target;
    
    cout<<"enter the size of row";
    cin>>row;
    cout<<"enter the size of col";
    cin>>col;
    

    vector<vector<int>> mat(row, vector<int>(col));

    cout<<"enter the elements of a matrix is:";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
     cin>>mat[i][j];
    }

     cout<<"enter the target element\n";
    cin>>target;

    
      cout<<" matrix is:\n";
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"congratulations u have successfully found the element"<< binarysearch_2d(mat,row,col,target);
    return 0;
}