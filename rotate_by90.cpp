#include<iostream>
#include<vector>

using namespace std;
void rotate_by90(vector<vector<int>>& mat, int row, int col) {
   // vector<vector<int>> arr(col, vector<int>(row)); // Transposed matrix
    // Transpose logic without creating any extra array
    for(int i=0;i<row-1;i++)
    {
        for(int j=i+1;j<col;j++){
           swap(mat[i][j], mat[j][i]);
        }
        
    }

    // for reverse each row of a matrix

    for(int i=0;i<row;i++){
        int start=0,end=col-1;
        while(start<end){
            swap(mat[i][start],mat[i][end]);
            start++;
            end--;
        }

    }

     cout << "Matrix after rotating 90 degrees:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


}
int main()
{
    int row,col;
    
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
     
      cout<<" matrix is:\n";
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    rotate_by90(mat,row,col);

    return 0;
     

    
    
}