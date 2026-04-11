#include<stdio.h>
#include<stdlib.h>
void dijikstras(int n,int cost[10][10],int s,int dist[10]){
    int count=1,v,visited[10],min;
    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    while(count<=n){
        min=999;
            for(int i=1;i<=n;i++){
                if(dist[i]<min && visited[i]==0){
                    min=dist[i];
                    v=i;
                }
            }
            visited[v]=1;
            count++;
            for(int i=1;i<=n;i++){
                if(dist[v]+cost[v][i]<dist[i])
                dist[i]=dist[v]+cost[v][i];
            }
    }
}

void dijikstras1(int v,int cost[10][10],int s,int dist[10]){
    int count=0,visited[10];
    for(int i=0;i<v;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    while(count<=v){
        int min=999;
        for(int i=0;i<v;i++){
            if(min>dist[i] && visited[i]==0){
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        count++;
        for(int i=0;i<v;i++){
            if(dist[v]+cost[v][i]<dist[i])
        }
    }
}
int main(){
    int n,s,cost[10][10],count=1,dist[10],visited[10];
    printf("enter no of nodes\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                    cost[i][j]=999;        
        }
    }
    printf("enter source vertex\n");
    scanf("%d",&s);
    dijikstras(n,cost,s,dist);

    // print path
    printf("shortest distance from%d is :\n",s);
    for(int i=1;i<=n;i++){
        if(s != i)
        printf("%d -> %d = %d \n",s,i,dist[i]);
    }
    return 0;

}