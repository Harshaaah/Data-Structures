#include <stdio.h>
#define MAX 20

int graph[MAX][MAX],stack[MAX],visited[MAX],indegree[MAX]={0},n;

void dfs(int node){
    int i;
    visited[node]=1;
    printf("%d ",node);
    
    for(i=0;i<n;i++){
        
        if(graph[node][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}
void dfs_fill(){
    
    int i;
    for(i=0;i<n;i++){
        
        if(!visited[i]){
            dfs(i);
        }
    }
}
void bfs(int node){
    
    int queue[MAX]={0},front=0,rear=0,i;
    
    visited[node]=1;
    queue[rear++]=node;
    
    while(front<rear){
        
        int current=queue[front++];
        printf("%d ",current);
        
        for(i=0;i<n;i++){
            
            if(graph[current][i]==1 && !visited[i]){
                
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}
void bfs_fill(){
    
    for(int i=0;i<n;i++){
        
        if(!visited[i]){
            bfs(i);
        }
    }
}
void topological(){
    int top=-1,i;
    
    for(i=0;i<n;i++){
        if(indegree[i]==0){
            
            stack[++top]=i;
        }
    }
    while(top!=-1){
        
        int current=stack[top--];
        printf("%d ",current);
        
        for(i=0;i<n;i++){
            
            if(graph[current][i]==1){
                
                indegree[i]--;
        
                if(indegree[i]==0){
                
                    stack[++top]=i;
                }
            }
        }
    }
    
}

int main()
{
    int i,j,v,choice;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==1){
                indegree[j]++;
            }
        }
    }
    
    while(1){
        
        printf("\nChoose an algorithm to run:\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Topological Sort\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Depth First Search (DFS):\n");
            for (i = 0; i <= n; i++) visited[i] = 0;
            printf("starting vertex:");
            scanf("%d",&v);
            dfs(v);
            dfs_fill();
            break;
        case 2:
            printf("Breadth First Search (BFS):\n");
            for (i = 0; i <= n; i++) visited[i] = 0;
            printf("starting vertex:");
            scanf("%d",&v);
            bfs(v);
            bfs_fill();
            break;
        case 3:
            printf("Topological Sort:\n");
            topological();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
