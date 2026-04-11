#include<iostream>
#include<vector>
using namespace std;
void missing_repeating(vector<int>& arr, int n){
    // decrease array by 1
   for(int i=0;i<n;i++)
   arr[i]--;

    for(int i=0;i<n;i++){
        arr[arr[i]%n] += n;
    }
// for repeating
 int repeating = -1, missing = -1;
  for(int i=0;i<n;i++){
    if(arr[i]/n==2){
        repeating=i+1;
        break;
    }
// for  missing
    else if(arr[i]/n==0){
        missing=i+1;
        break;
    }
  }     

 // Output the results
    cout << "Repeating: " << repeating << endl;
    cout << "Missing: " << missing << endl;
}
int main()
{
    int n;
   vector<int> arr(n);
   cout<<"enter the size of array\n";
   cin>>n;
   cout<<"enter the elements \n";
   for(int i=0;i<n;i++)
   cin>>arr[i];

  cout<<" the elements are \n";
   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
   
// calling the function

missing_repeating(arr,n);

return 0;

}