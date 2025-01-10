#include<stdio.h>
#include<stdbool.h>
#define MAX 10
int graph[MAX][MAX],transpose[MAX][MAX],stack[MAX];
bool visited[MAX];
int top=-1,n=0;
void dfs_fillstack(int node){
    int i;
    visited[node]=1;
    for(i=0;i<n;i++){
        if(graph[node][i]==1 && !visited[i]){
            dfs_fillstack(i);
        }
    }
    stack[++top]=node;
}
void reversegraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            transpose[i][j]=graph[j][i];
        }
    }
}
void dfs(int node){
    visited[node]=1;
    printf("%d ",node);
    for(int i=0;i<n;i++){
        if(transpose[node][i]==1 && !visited[i])
            dfs(i);
    }
}
void kosaraju(int n){
    int i,j;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs_fillstack(i);
        }
    }
    
    reversegraph();
    
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    
    printf("SCC components:");
    
    while(top!=-1)
    {
         int vertex=stack[top--];
        if(!visited[vertex]){
            dfs(vertex);
            printf("\n");
        }
        
    }
}
int main(){
    int i,j;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    printf("enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
        
    }
    kosaraju(n);
}
