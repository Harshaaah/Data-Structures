#include<stdio.h>
#define MAX 10
int cost[MAX][MAX],n,i,j,visited[MAX]={0},ne=0,min,mincost=0;

int main(){
    int u,v;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    printf("\nenter the adjacency matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           scanf("%d",&cost[i][j]); 
           if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    
    visited[0]=1;
    while(ne<n-1){
        min=999;
        for(i=0;i<n;i++){
            
            if(visited[i]==1){
                for(j=0;j<n;j++){
                
                    if(cost[i][j]<min && visited[j]==0){
                    
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        
        if(visited[v]==0){
            
            visited[v]=1;
            printf(" edge %d :(%d-%d)  cost:%d\n",ne++,u,v,min);
            mincost+=min;
            
        }
        
        cost[u][v]=999;
        cost[v][u]=999;
    }
    printf("mincost:%d",mincost);
    
    
}
