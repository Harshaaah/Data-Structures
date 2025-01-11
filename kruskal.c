#include<stdio.h>
#include<stdlib.h>

int n,u,v,cost[20][20],parent[20];
int mincost=0,min,ne=0,a,b;

int find(int i){
    
    while(parent[i]){
        i=parent[i];
    }
    return i;
}
int uni(int i,int j){
    
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main(){
    int i,j;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    
    printf("enter adajency matrix:");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                
                cost[i][j]=999;
            }
        }
        
    }
    
    while(ne<n-1){
        min=999;
        for(i=0;i<n;i++){
            
            for(j=0;j<n;j++){
                
                if(cost[i][j]<min){
                    
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        
        a=find(u);
        b=find(v);
        
        if(uni(a,b)){
            
            printf("edge %d : (%d-%d) cost:%d\n",ne++,u,v,min);
            mincost+=min;
        }
        cost[u][v]=999;
        cost[v][u]=999;
        
    }
    
    printf("mincost:%d",mincost);
    return 0;
}
