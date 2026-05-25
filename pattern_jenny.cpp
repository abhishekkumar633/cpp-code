#include<iostream>
#include<vector>
using namespace std;

void Half_diamond(){
    int num=1;
     for(int i=1;i<=10;i++){
        for(int space=1;space<=10-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<< num <<" ";
            num++;
        }
        cout<<"\n";
    }
}

void serial_number(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
    }
}

int counting_pattern(){
    int num=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<"\n";
    }
    return num;
}

void right_side_star_pattern() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n - i; space++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pyramid(){
    int rows=5;
    for(int i=1;i<=rows;i++){
        for(int space=1;space<=rows-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void inverted_pyramid(){
    int rows=5;
    for(int i=rows;i>=1;i--){
        for(int space=1;space<=rows-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void butterfly_print(){
    int rows=5;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //int i;
    for(int k=rows-1;k>=1;k--){
        for(int l=1;l<=k;l++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printAllTarget_subArray(vector<int>arr,int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum==target){
                for(int k=i;k<=j;k++){
                    cout<<arr[k]<<' ';
                }
                cout<<endl;
            }
        }
    }
}

// centerred triangle 
void print_triangle_pattern(int row){
    for(int i=1;i<=row;i++){
        for(int space=1;space<=row-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
   //Half_diamond();
  // cout<< serial_number();
  // counting_pattern();
//     vector<int> arr = {3,4,-7,1,3,3,1,-4};
//     int target = 7;
//    printAllTarget_subArray(arr,target);
  // right_side_star_pattern();
   //pyramid();
   //inverted_pyramid();
   //butterfly_print();
   print_triangle_pattern(5);
}