#include <stdio.h>
struct obj {
    float weight;
    float profit;
    float x;
    int ogpos;
    float ratio;
};
struct obj init(float w,float p,int og) {
    struct obj ans;
    ans.profit = p;
    ans.weight = w;
    ans.x = p/w;
    ans.ogpos = og;
    ans.ratio=0;
    return ans;
}
void sortX(struct obj a[],int n) {
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
void sortWeight(struct obj a[],int n) {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n-i-1;j++) {
            if(a[j].weight > a[j+1].weight) {
                struct obj temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void sortProfit(struct obj a[],int n) {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n-i-1;j++) {
            if(a[j].profit < a[j+1].profit) {
                struct obj temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void sortPosition(struct obj a[],int n) {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n-i-1;j++) {
            if(a[j].ogpos > a[j+1].ogpos) {
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
    
    while(cap > c) {
        for(int i=0;i<n;i++) {
            if(cap > a[i].weight+c) {
                c += a[i].weight;
                p += a[i].profit;
                a[i].ratio=1;
            }
            else if(c+a[i].weight > cap) {
                float space = cap-c;
                c += space;
                p += (space/a[i].weight) * a[i].profit;
                a[i].ratio = space/a[i].weight;
                i++;
                break;
            }
        }
    }
    printf("Total profit: %f\nTotal Weight:%f",p,c);
}
void display(struct obj a[],int n) {
    sortPosition(a,n);
    for (int i = 0;i<n;i++) {
        printf("Object %d inserted %f\n",a[i].ogpos+1,a[i].ratio);
        a[i].ratio=0;
    }
}
int main() {
    printf("Enter the number of items:");
    int n;
    float w,p,c;
    struct obj a[n];
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        printf("Enter the weight and profit of object %d\n",i+1);
        scanf("%f%f",&w,&p);
        a[i] = init(w,p,i);
    }
    printf("Enter the capacity of the sack");
    scanf("%f",&c);
    int ch;
    do {
        printf("Press 1 to sort by minimum weight\nPress 2 to sort by maximum profit\nPress 3 to sort by P/W\nPress 4 to exit:");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                sortWeight(a,n);
            fillsack(a,n,c);
            display(a,n);
            break;
            case 2:
                sortProfit(a,n);
            fillsack(a,n,c);
            display(a,n);
            break;
            case 3:
                sortX(a,n);
            fillsack(a,n,c);
            display(a,n);
            break;
            case 4: break;
            default: printf("Wrong choice");
        }
    }while(ch != 4);
}
