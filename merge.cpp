#include<iostream>
#include<vector>
using namespace std;


void merge(int arr[],int start,int end,int mid){
    vector<int>temp(end-start+1);
    int index=0,left=start,right=mid+1;
    while(left<=mid && right<=end)
    {
        if(arr[left]<arr[right])
        {
            temp[index]=arr[left];
            left++;
            index++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }
    }

    while(left<=mid)
    {
        temp[index]=arr[left];
        left++;
        index++;
    }

    while(right<=end)
    {
        temp[index]=arr[right];
        right++;
        index++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}
void merge_sort(int arr[],int start,int end){
    if(start==end)
    return;
    int mid=start+(end-start)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,end,mid);
}

int partition(int arr[],int start,int end){
    int pos=start;
    for(int i=start;i<=end;i++)
    {
        if(arr[i]<=arr[end])
        {
            swap(arr[i],arr[pos]);
            pos++;
        }
    }
    return pos-1;
}

void quick_sort(int arr[],int start,int end){
    if(start>=end)
    return;
    int pivot=partition(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);
}


int main(){
    int arr[]={23,54,12,78,14,27};

   // merge_sort(arr,0,5);

    quick_sort(arr,0,5);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}