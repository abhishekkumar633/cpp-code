#include<stdio.h>
#include<stdlib.h>
void dijikstras(int n,int cost[20][20],int s,int dist[20]){
    int count=1,visited[20],min,v;
    // initially assigned all the vertices with 0 bcz i havenot seen yet
    for(int i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i]; 
    }
    visited[s]=1;
    dist[s]=0;

    while(count < n){
        min=999;
        for(int i=1;i<=n;i++){
            if(dist[i]<min && visited[i]==0){
                min=dist[i];
                v=i;
            }
           
        }
        visited[v]=1; // now i have visited this node
        count++;

        // now updation will take place for each node
        for(int i=1;i<=n;i++){
            if(dist[i]>dist[v]+cost[v][i]){
                dist[i]=dist[v]+cost[v][i];
            }
        }
    }

}


int main(){
    int cost[20][20],dist[20],s,n;
    printf("enter no of nodes\n");
    scanf("%d",&n);

    printf("read cost matrix\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                    cost[i][j]=999;
            }
        }

        printf("Read source vertex\n");
        scanf("%d",&s);

        dijikstras(n,cost,s,dist);
        printf("shortest Path from %d is\n",s);
            for(int i=1;i<=n;i++){
                if(s != i)
                    printf("%d->%d=%d\n",s,i,dist[i]); // it will print shortest path between source to destination;
            }

            return 0;
}