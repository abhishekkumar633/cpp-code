#include<iostream>
using namespace std;
int peekindex_inmountedarray(int arr[],int n){
    int start=0,end =n-1,mid;
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]>mid-1 && arr[mid]>mid+1)
            return mid;
        else if(arr[mid]>mid-1)
            start=mid+1;
        else
            end= mid-1;
    }
    return -1;
}
int main()
{
    int n;
    int arr[100];  ;
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int peakIndex = peekindex_inmountedarray(arr, n);
    cout << "Peak element is at index: " << peakIndex << " with value: " << arr[peakIndex] << endl;
    return 0;
}

// #include<iostream>
// using namespace std;

// int peak_index_in_mountain_array(int arr[], int n) {
//     int start = 0, end = n - 1;
    
//     while (start < end) {
//         int mid = start + (end - start) / 2;

//         // Compare mid with its next element
//         if (arr[mid] < arr[mid + 1]) {
//             // Move to the right half
//             start = mid + 1;
//         } else {
//             // Move to the left half, since this could be the peak
//             end = mid;
//         }
//     }
//     // When start == end, we have found the peak index
//     return start;
// // }

// // int main() {
// //     int n;
// //     int arr[100];
    
// //     cout << "Enter the size of array: ";
// //     cin >> n;

// //     if (n < 3) {
// //         cout << "Invalid input! A mountain array must have at least 3 elements." << endl;
// //         return 1;
// //     }

// //     cout << "Enter the elements: ";
// //     for (int i = 0; i < n; i++) {
// //         cin >> arr[i];
// //     }
    
// //     int peakIndex = peak_index_in_mountain_array(arr, n);
// //     cout << "Peak element is at index: " << peakIndex << " with value: " << arr[peakIndex] << endl;

// //     return 0;
// // }
