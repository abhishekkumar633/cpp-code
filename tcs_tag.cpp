#include<iostream>
#include<vector>
using namespace std;
// int count_total_student(int arr[][100],int n,int m){
//     int count=0;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=0;j<m;j++){
//             sum += arr[i][j];
//         }
//         if(sum/m > 50){
//             count++;
//         }
//     }
//     return count;
// }
int count_total_student(vector<vector<int>>&marks,int n,int m){
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum += marks[i][j];
        }
        if(sum/m > 50){
            count++;
        }
    }
    return count;
}
int main(){
     int n,m;
    vector<vector<int>> marks(n,vector<int>(m));//
     cin>>n>>m;
    // int arr[100][100];
    // cout<<"enter matrix\n";  
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr[i][j];
    //     }
    // }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>marks[i][j];
        }
    }

    // cout<<"matrix is :"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    
    //cout<<count_total_student(arr,n,m);
    cout<<count_total_student(marks,n,m);
}