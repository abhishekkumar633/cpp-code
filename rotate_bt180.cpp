#include<iostream>
#include<vector>
using namespace std;
void rotate_by180(vector<vector<int>>& mat, int row, int col){

    // first swapping it as a columnwise
    for(int j=0;j<col;j++){
        int start=0,end=row-1;
        while(start<end){
            swap(mat[start][j],mat[end][j]);
            start++;
            end--;
        }
    }

    // now finally  reverse  it as a row wise to get 180 rotation
    for(int i=0;i<row;i++){
        int start=0,end=col-1;
        while(start<end){
             swap(mat[i][start],mat[i][end]);
             start++;
             end--;

        }

    }

    // printing the rotaed matrix

     cout<<" matrix after rotating is:\n";
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

    // printing the matrix....
     
      cout<<" matrix is:\n";
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    rotate_by180(mat,row,col);

    return 0;
}