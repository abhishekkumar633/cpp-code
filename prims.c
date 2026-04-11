#include<stdio.h>
#define MAX 100
#define INF 999
int cost[MAX][MAX],visited[MAX],v;
void prims(int source){
    int mincost=0,count=0;
    visited[source]=1;
    while(count<v-1){
       int  min=MAX,a=-1,b=-1;
        for(int i=0;i<v;i++){
            if(visited[i]){
                for(int j=0;j<v;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(a !=-1 && b != -1){
            printf("%d->%d=%d\n",a,b,cost[a][b]);
            mincost += cost[a][b];
            visited[b]=1;
            count++;
        }
    }
     printf("Total cost of MST: %d\n", mincost);
}
int main(){
    printf("ente no of vertices\n");
    scanf("%d",&v);
    
    for(int i=0;i<v;i++){
        visited[i]=0;
    }

    printf("enter the weight of edges\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=INF;
        }
    }
    int source;

    printf("enter source vertex\n");
    scanf("%d",&source);
    prims(source);


    return 0;
}