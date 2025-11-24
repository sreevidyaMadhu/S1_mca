#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100
int DFS(int node,int n,int graph[][MAX_NODES],int visited[],int recStack[],int parent);
void main()
{
    int n;
    printf("enter the number of nodes:");
    scanf("%d",&n);


    int A[MAX_NODES][MAX_NODES];
    printf("enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
            if(!A[i][j])
                A[i][j]=INT_MAX;
        }
    }

    int mst[MAX_NODES][MAX_NODES]={0};
    int edge_count=0,cost=0;
    printf("the edges in the minimum spanning tree are:");
    while(edge_count<n-1){
        int min = INT_MAX,u,v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]<min){
                    min=A[i][j];
                    u=i,v=j;
                }
            }
        }
        mst[u][v]=min;
        A[u][v]=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int visited[MAX_NODES]={0},recStack[MAX_NODES]={0};
            if(DFS(i,n,mst,visited,recStack,-1)){
                mst[u][v]=0;
                break;
            }
        }
        if(!mst[v][u]&&mst[u][v]!=0){
            cost+=min;
            printf("{%d,%d}=%d\n",u,v,mst[u][v]);
            edge_count++;
        }

    }
    printf("Minimum cost:%d\n",cost);

}

int DFS(int node,int n,int graph[][MAX_NODES],int visited[],int recStack[],int parent){
    if(!visited[node]){
        visited[node]=recStack[node]=1;

        for(int i=0;i<n;i++){
            if(graph[node][i]!=0){
                if(!visited[i])
                DFS(i,n,graph,visited,recStack,node);
            else if(recStack[i]&& i!=parent)
            return 1;
            }
        }
    }
    recStack[node]=0;
    return 0;
}