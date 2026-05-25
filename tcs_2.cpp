#include <iostream>
using namespace std;

int main() {
    int row, col;

    cout << "Enter row: ";
    cin >> row;

    cout << "Enter col: ";
    cin >> col;

    int arr1[100][100];
    int arr2[100][100];

    cout << "Enter first matrix:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr1[i][j];
        }
    }

    cout << "Enter second matrix:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr2[i][j];
        }
    }

    int sum = 0;

    if(row > 2 && col > 2){
        sum = arr1[2][2] + arr2[2][2];
        cout << "Sum = " << sum;
    } else {
        cout << "Matrix too small for index (2,2)";
    }

    return 0;
}