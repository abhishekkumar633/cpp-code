#include<iostream>
using namespace std;
void transpose(int mat[][col],int row,int col){
    
    int i,j;
    int arr[j][i];
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    arr[j][i]=mat[i][j];

    cout<<"transpose of a matrix is:";
    for(int i=0;i<row;i++)
     for(int j=0;j<col;j++){
         cout<<mat[i][j]<<" ";
     }
     cout<<endl;
    
}
int main()
{
    int row,col;
    int mat[row][col];
    cout<<"enter the size of row";
    cin>>row;
    cout<<"enter the size of col";
    cin>>col;

    cout<<"enter the elements of a matrix is:";
    for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)
     cin>>mat[i][j]<<" ";

    transpose(mat,row,col);

     

    
    
}