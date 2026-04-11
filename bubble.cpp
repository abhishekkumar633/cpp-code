#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int arr[],int n) {  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                // int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
 void printArray(int arr[],int n){
    for (int j=0;j<n;j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}
void bubble1_sorting(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}


string sort_character(string str){
     vector<int>lower(26,0); // used for storiung count...
     vector<int>upper(26,0); // used for storiung count..

     // for storing the count of each character
     for(int i=0;i<str.size();i++)
     {
        if(str[i]=='a'|| str[i]=='e'||str[i]=='i'|| str[i]=='o'|| str[i]=='u')
        {
             lower[str[i]-'a']++;
             str[i]='#';
        }      
     }

      for(int i=0;i<str.size();i++)
     {
        if(str[i]=='A'|| str[i]=='E'||str[i]=='I'|| str[i]=='O'|| str[i]=='U')
        {
             upper[str[i]-'A']++;
              str[i]='#';
        }      
     }

     // Now sort the string for upper case letter

     string ans; 
     for(int i=0;i<26;i++)
     {
        char c = i+'A';
        while(upper[i])
        {
            ans += c;
            upper[i]--;
        }
     }

      for(int i=0;i<26;i++)
     {
        char c = i+'a';
        while(lower[i])
        {
            ans += c;
            lower[i]--;
        }
     }

     int first=0,second=0; //two pointer 

    while(second<ans.size())
    {
        if(str[first]=='#')
        {
            str[first] = ans[second];
            second++;
        }
        first++;
    }

    return str;

     
}


// selection sort

void selection_sort(int arr[],int n){

    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
            index=j;
        }
        swap(arr[index],arr[i]);
    }
}

void insertion_sort(int arr[],int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            swap(arr[j],arr[j-1]);
            else
                break;
        }
    }
}



int main() {
    // //vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
     int arr[]={64, 34, 25, 12, 22, 11, 90};

    // cout << "Original array: ";
    // printArray(arr,7);

    // bubbleSort(arr,7);

    // cout << "Sorted array: ";
    // printArray(arr,7);

    // return 0;

    // string str;
    // cout<<"enter the string\n";
    // getline(cin,str);

    // cout<<"sorted string is :\n "<<sort_character(str);


    //selection_sort(arr,7);a

    insertion_sort(arr,7);
    printArray(arr,7);


}
