#include<stdio.h>
#include<stdlib.h>
struct job{
    int id;
    int profit;
    int deadline;
};
int compare(const void*a,const void *b){
    struct job* j1=(struct job*)a;
    struct job* j2=(struct job*)b;
    return j2->profit-j1->profit;
}
int main(){
    int n;
    printf("enter no of jobs to be executed\n");
    scanf("%d",&n);
    struct job jobs[n];

    printf("enter job id profit deadline\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&jobs[i].id,&jobs[i].profit,&jobs[i].deadline);
    }

    // sorting the job considering profit;
    qsort(jobs,n,sizeof(struct job),compare);

    int maxdeadline=0;
    for(int i=0;i<n;i++){
        if(jobs[i].deadline>maxdeadline)
        maxdeadline=jobs[i].deadline;
    }

    // time slot
    int slot[maxdeadline];

    for(int i=0;i<maxdeadline;i++){
        slot[i]=-1;
    }
    int totalprofit=0;
    // select job;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=jobs[i].id;
                totalprofit += jobs[i].profit;
                break;
            }
        }
    }

    printf("total profit is %d:",totalprofit);
    return 0;


}