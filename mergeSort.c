#include<stdio.h>
#define MAX 10
int A[MAX],B[MAX],C[20],asize=0,bsize=0,csize=0;

void read(int arr[],int *size){
    int i;
    for(i=0;i<*size;i++){
        printf("enter element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    
    
}

void print(int arr[],int *size){
    
    int i;
    for(i=0;i<*size;i++){
        printf("%d",arr[i]);
    }
}

void sort(int arr[],int *size){
    int i,j;
    
    for(i=0;i<*size-1;i++){
        for(j=0;j<*size-i-1;j++){
            
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
    
    
}

int main(){
    
    printf("enter the size of 1st array:");
    scanf("%d",&asize);
    read(A,&asize);
    printf("enter size of 2nd array:");
    scanf("%d",&bsize);
    read(B,&bsize);
    
    sort(A,&asize);
    printf("1st array elements sorted:");
    print(A,&asize);
    sort(B,&bsize);
    printf("\n2nd array elements sorted:");
    print(B,&bsize);
    int i,j;
    
    for(i=0;i<asize;i++){
        
        C[i]=A[i];
    }
    csize=asize;
    int flag=0;
    for(i=0;i<bsize;i++){
        for(j=0;j<asize;j++){
            
            if(B[i]==A[j]){
                flag=1;
            }
        }
        
        if(flag==0){
            
            C[csize]=B[i];
            csize+=1;
        }
    }
    
    sort(C,&csize);
    printf("\nmerged and sorted array:");
    print(C,&csize);
    
    
    
}
