#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int A[MAX],asize=0;
int B[MAX],bsize=0;
int S[MAX],ssize=0;
int bitA[MAX];
int bitB[MAX];
int i,j;

void readSet(int arr[],int *size){
    for(i=0;i<*size;i++){
    printf("enter the element %d:",i+1);
    scanf("%d",&arr[i]); 
    }
}
void printbitsets(){
    printf("Bitstring set A:");
    for(i=0;i<ssize;i++)
        printf("%d",bitA[i]);
    printf("\nBitstring set B:");
    for(i=0;i<ssize;i++)
        printf("%d",bitB[i]);
    
}
void bitstring(){
    for(i=0;i<ssize;i++){
        bitA[i]=0;
        bitB[i]=0;
    }
    for(i=0;i<asize;i++){
        for(j=0;j<ssize;j++)
        {
            if(A[i]==S[j]){
                bitA[j]=1;
                break;
            }
        }
    }
    for(i=0;i<bsize;i++){
        for(j=0;j<ssize;j++)
        {
            if(B[i]==S[j]){
                bitB[j]=1;
                break;
            }
        }
    }
    printbitsets();
    
}
void setunion(){
    int uni[MAX];
    for(i=0;i<ssize;i++)
    {
        uni[i]=bitA[i] | bitB[i];
    }
    printf("\nUnion of set A and B:");
    for(i=0;i<ssize;i++)
        printf("%d",uni[i]);
    
    printf("\nunion sets elements:");
    
    for(int i=0;i<asize;i++)
        printf("%d",A[i]);
    int flag;
    for(int i=0;i<ssize;i++){
        for(int j=0;j<bsize;j++){
            if(S[i]==B[j]){
                for(i=0;i<asize;i++){
                    if(B[j]==A[i]){
                        flag=1;
                    }               
                }
                if(!flag){
                    printf("%d",B[j]);
                }
            }
            
        }
        
        
    }
}
void intersection(){
    int inter[MAX];
    for(i=0;i<ssize;i++)
        inter[i]=bitA[i] & bitB[i];
    printf("\nintersection of set A and B:");
    for(i=0;i<ssize;i++)
        printf("%d",inter[i]);
}
void AminusB()
{
    int AB[MAX];
    for (int i = 0; i < ssize; i++)
    {
       AB[i] = bitA[i] & (1 - bitB[i]);
    }
    printf("Difference (A - B): ");
     for(i=0;i<ssize;i++)
        printf("%d",AB[i]);
   
    
}
void BminusA()
{
    int BA[MAX];
    for (int i = 0; i < ssize; i++)
    {
       BA[i] = bitB[i] & (1 - bitA[i]);
    }
    printf("Difference (B - A): ");
     for(i=0;i<ssize;i++)
        printf("%d",BA[i]); 
}

int main()
{
   
    //Read universal set
    do{
    printf("Enter the size of universal set(max 20):");
    scanf("%d",&ssize);
    
    if(ssize>MAX){
        printf("size limit exceeded!!\n");
    }
    }while(ssize>MAX);
    for(i=0;i<ssize;i++){
    printf("enter the element %d:",i+1);
    scanf("%d",&S[i]); 
    }
    //Read set A
    do{
    printf("enter the size of set A(max %d):",ssize);
    scanf("%d",&asize);
    if(asize>ssize)
        printf("invalid size!! size not exceeded than universal set size\n");
    }while(asize>ssize);
    readSet(A,&asize);
    
    //Read set B
    do{
    printf("enter the size of set B(max %d):",ssize);
    scanf("%d",&bsize);
    if(bsize>ssize)
        printf("invalid size!! size not exceeded than universal set size\n");
    }while(bsize>ssize);
    readSet(B,&bsize);
    bitstring();
    int choice;
    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Union of A and B\n");
        printf("2. Intersection of A and B\n");
        printf("3. Difference (A - B)\n");
        printf("4. Difference (B - A)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                setunion();
                break;
            case 2:
                intersection();
                break;
            case 3:
                AminusB();
                break;
            case 4:
                BminusA();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 5);
    return 0;
}
