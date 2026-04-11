#include<stdio.h>
typedef struct{
    int id;
    int deadline;
    int profit;
}job;
void profit_sort(job jobs[],int n){
    job temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(jobs[j].profit<jobs[j+1].profit){
                temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main(){
    int n;
    printf("ente no of jobs to be performed\n");
    scanf("%d",&n);
    job jobs[n];
    int totalprofit=0;
    int max_deadline=0;

    printf("enter job id,deadline,profit for different job\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
        if(jobs[i].deadline>max_deadline){
            max_deadline=jobs[i].deadline;
        }
    }

    // sort job considering profit value
    profit_sort(jobs,n);

    // time slot partition
    int result[max_deadline+1];
    for(int i=0;i<=max_deadline;i++){
        result[i]=-1;
    }

    // assigning job values to specific slot
    for(int i=0;i<n;i++){
        for(int j=min(max_deadline,jobs[i].deadline);j>0;j--){
            if(result[j]==-1){
                result[j]=i;
                totalprofit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs:\n");
    for (int i = 1; i <= max_deadline; i++) {
        if (result[i] != -1) {
            printf("Job %d (Profit: %d, Deadline: %d)\n",
                   jobs[result[i]].id, jobs[result[i]].profit, jobs[result[i]].deadline);
        }
    }

    printf("Total Profit: %d\n", totalprofit);

    return 0;
       
   

}