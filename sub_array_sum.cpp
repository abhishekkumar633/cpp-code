#include<iostream>
#include<unordered_map>
using namespace std;
int sub_array_sumequals_to_zero(int arr[],int n){
    int total=0;
    unordered_map<int,int>m; // its basically track the key and value of tbhe array
    m[0]=1; // assigning the initisl value like (0,1);
    int prefix_sum=0;
    for(int i=0;i<n;i++)
    {
        prefix_sum += arr[i];
        if(m.count(prefix_sum))
        { 
            total += m[prefix_sum];
            m[prefix_sum]++;
        }
        else{
            m[prefix_sum]=1;
        }
    }
    return total;
}

int main()
{
    int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};  
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = sub_array_sumequals_to_zero(arr, n);
    cout << "Number of subarrays with sum zero: " << result << endl;

    return 0;
}