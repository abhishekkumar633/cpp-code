#include <stdio.h>
struct obj {
    float weight;
    float profit;
    float x;
    int ogpos;
};
struct obj init(float w,float p,int og) {
    struct obj ans;
    ans.profit = p;
    ans.weight = w;
    ans.x = p/w;
    ans.ogpos = og;
    return ans;
}
void sort(struct obj a[],int n) {
   for(int i = 0;i<n;i++) {
       for(int j = 0;j<n-i-1;j++) {
           if(a[j].x < a[j+1].x) {
               struct obj temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
       }
   }
}
void fillsack(struct obj a[],int n,float cap) {
    float c = 0;
    float p = 0;
    int i=0;
    while(cap > c) {
        for(;i<n;i++) {
            if(cap > a[i].weight+c) {
                c += a[i].weight;
                p += a[i].profit;
                printf("Object %d inserted 1\n",a[i].ogpos);
            }
            else if(c+a[i].weight > cap) {
                float space = cap-c;
                c += space;
                p += (space/a[i].weight) * a[i].profit;
                printf("Object %d inserted %f\n",a[i].ogpos,space/a[i].weight);
                i++;
                break;
            }
        }
    }
    for(;i<n;i++) {
        printf("Object %d inserted 0\n",a[i].ogpos);
    }
    printf("Total profit: %f\nTotal Weight:%f",p,c);
}
int main() {
    int n;
    float w,p,c;
    struct obj a[n];
    printf("Enter the number of items:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        printf("Enter the weight and profit of object %d\n",i);
        scanf("%f%f",&w,&p);
        a[i] = init(w,p,i);
    }
    printf("Enter the capacity of the sack");
    scanf("%f",&c);
    sort(a,n);
    fillsack(a,n,c);
}