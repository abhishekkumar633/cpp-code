#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct edges{
    int src,dest,weight;
};

int parent[MAX];

int find(int i){
    while(parent[i] != -1)
    i=parent[i];
    return i;
}

void unionset(int u,int v){
    int uroot=find(u);
    int vroot=find(v);
    parent[uroot]=vroot;
    
}


int compare(const void *a,const void *b){
    struct edges *e1= (struct edges *)a;
    struct edges *e2= (struct edges *)b;
    return e1->weight-e2->weight;
}


int main(){
    int v,e;
    struct edges edge[MAX];
    printf("enter no of vertices and edges\n");
    scanf("%d %d",&v,&e);

    // input src dest weight
    printf("enter src dest weight\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edge[i].src,&edge[i].dest,&edge[i].weight);
    }

    qsort(edge,e,sizeof(struct edges),compare);

    for(int i=0;i<v;i++){
        parent[i]=-1;
    }

    int count=0,totalweight=0;
    // detecting cycle
    for(int i=0;i<e && count < v-1;i++){
        int u=edge[i].src;
        int v=edge[i].dest;

        if(find(u) != find(v)){
            printf("%d->%d==%d\n",u,v,edge[i].weight);
            unionset(u,v);
            totalweight += edge[i].weight;
            count++;
        }
        
    }

        printf("Total weight of MST: %d\n", totalweight);
        return 0;
    



}