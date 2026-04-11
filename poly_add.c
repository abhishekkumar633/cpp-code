#include<stdio.h>
int main()
{
  int n,m;
  int arr1[100]={0};
  int arr2[100]={0};
  int sum[100]={0};
  int prod[100]={0};
  printf("enter the degree of first polynomial\n");
  scanf("%d",&n);

  printf("insert the value of coefficient of first polynomial");
  for(int i=0;i<=n;i++)
  {
    scanf("%d",&arr1[i]);
  }


    printf("enter the degree of second polynomial\n");
  scanf("%d",&m);

  printf("insert the value of coefficient of first polynomial");
  for(int i=0;i<=m;i++)
  {
    scanf("%d",&arr2[i]);
  }


int p;
if(m>n)
p=m;

else{
    p=n;
}

for(int i=0;i<=p;i++)
{
    sum[i]=arr1[i]+arr2[i];
}

// for printing the output of the polynomial;

for(int i=0;i<=p;i++)
printf("%d ",sum[i]);


// for multiplication 

for(int i=0;i<=n;i++)
{
    for(int j=0;j<=m;j++)
    prod[i+j]+=arr1[i]*arr2[j];
}

// for multiplication output

for(int i=0;i<=n+m;i++)
{
    for(int j=0;j<=n+m;j++)
    printf("%d ",prod[i+j]);
}
return 0;
}