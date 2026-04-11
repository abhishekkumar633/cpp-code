#include<iostream>
using namespace std;
int Trapping_Rainwater(int height[],int n){
    int i,index=0,water=0;
    int maxleft=0,maxright=0,maxheight=height[0];

    // maximum height of building..........
    for(int i=1;i<n;i++){
        if(height[i]>maxheight){
            maxheight=height[i];
            index=i;
      }     
   }

   // for left part
   for(int i=0;i<index;i++){
    if(maxleft>height[i])
        water+=maxleft-height[i];
        else 
        maxleft=height[i];  
   }

   // for right part......
   for(int i=n-1;i>index;i--){
    if(maxright>height[i])
     water+=maxright-height[i];
        else 
        maxright=height[i];  
   }
   return water;
}
int main()
{
     int n;
    int height[100];
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    cin>>height[i];
    cout<<"total amount of water in unit is"<< Trapping_Rainwater(height,n);
}
