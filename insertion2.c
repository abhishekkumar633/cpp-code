#include <stdio.h>
int main()
{
    int i, n, pos, num, size;
    int arr[50];
    printf("enter the size of array\n");
    scanf("%d", &n);
    printf("enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf(" the elements of array are :\n");
    for (int i = 0; i < n; i++)
    {  
        printf("%d\n", arr[i]);
    }
    printf("for inserting  the elements in array :\n");
    printf("enter data which u want to insert\n");
    scanf("%d", &num);
    printf("enter position where u want to insert\n");
    scanf("%d", &pos);
    for (i =pos - 1; i >= size - 1; i++)
    {
        arr[i]= arr[i + 1];
        
    }
   
        size--;
         for (int i = 0; i < n-1  ; i++)
    {  
        printf("%d\n", arr[i]);
    }

    return 0;
}