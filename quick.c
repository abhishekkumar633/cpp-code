#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int quick(int arr[],int start,int end){
    int pos=start;
    for(int i=start;i<=end;i++){
        if(arr[i]<=arr[end]){

           swap(&arr[i],&arr[pos]);
           pos++;
        }
       
    }
     return pos-1;
}
void quick_sort(int arr[],int start,int end){
    if(start>=end)
    return;
    int pivot=quick(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);
}
int main(){
    int arr[20],n;
    printf("enter elements of the array\n");
    scanf("%d",&n);
    printf("enter elemnts\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}