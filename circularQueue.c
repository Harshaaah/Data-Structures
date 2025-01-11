#include<stdio.h>
#include<stdlib.h>

int *queue,item,front=-1,rear=-1,size=0;


void enqueue(){
 
 if(front==-1 && front==-1){
     
     front=0,rear=0;
     printf("\nenter the item to insert:");
     scanf("%d",&item);
     queue[rear]=item;
 }
 else if(front==(rear+1)%size){
     printf("queue is full");
 }
 else{
     
     printf("\nenter element to insert:");
     scanf("%d",&item);
     rear=(rear+1)%size;
     queue[rear]=item;
 }
}

void dequeue(){
    
    if(front==-1 && rear==-1){
        
        printf("\nunderflow");
        return;
    }
    else if(front==rear){
        item=queue[front];
        front=-1,rear=-1;
        printf("\ndeleted item %d",item);
    }
        
    else{
        
        item=queue[front];
        front=(front+1)%size;
        printf("\ndeleted item %d",item);
    }
}

void display(){
    
    int i;
    printf("\nelements:");
    for(i=front;i!=rear;i=(i+1)%size){
        
        printf("%d ",queue[i]);
    }
    printf("%d",queue[i]);
    
}
void search(){
    int flag=0;
    printf("\nenter the item to search:");
    scanf("%d",&item);
    for(int i=front;i!=rear;i=(i+1)%size){
        
        if(queue[i]==item){
            printf("\nitem %d present",item);
            flag=1;
        }
    }
    if(!flag){
        printf("\nthe item %d is not present in the queue",item);
    }
}

int main(){
    int choice;
    printf("enter the size of circular queue:");
    scanf("%d",&size);
    
    queue=(int*)malloc(size * sizeof(int));
    
    while(1){
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.search\n5.exit");
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
          
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                free(queue);
                exit(0);
            default:
                printf("\nInvalid Option");
                break;
    
        }
    }
}
