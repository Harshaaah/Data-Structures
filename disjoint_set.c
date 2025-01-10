#include<stdio.h>
#include<stdlib.h>
int elements[30];
struct node{
    int data;
    struct node *rep;
    struct node*next;
}*head[20],*tail[20];

static int count=0;

void makeSet(int x){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    new->rep=new;
    head[count]=new;
    tail[count]=new;
    count++;
}

struct node* find(int x){
    int i;
    struct node* temp;
    for(int i=0;i<count;i++){
        temp=head[i];
        while(temp!=NULL){
            if(temp->data==x){
                return temp->rep;
            }
            temp=temp->next;
        }
    }
    return NULL;
}

void unionSets(int x,int y){
    int i,j,pos1,pos2;
    struct node *tail2;
    struct node *rep1=find(x);
    struct node *rep2=find(y);
    if(rep1==NULL || rep2==NULL){
        printf("element not present");
        return;
    }
    if(rep1!=rep2){
        
        for(i=0;i<count;i++){
            if(head[i]==rep1){
                pos1=i;
                tail[i]->next=rep2;
            }
        }
        
        
        for(j=0;j<count;j++){
            if(head[j]==rep2){
                pos2=j;
                tail2=tail[j];
                tail[pos1]=tail2;
            }
        }
         for (i = pos2; i < count; i++) {
                    head[i] = head[i + 1];
                    tail[i] = tail[i + 1];
            }
        while(rep2!=NULL){
            rep2->rep=rep1;
            
            rep2=rep2->next;
            
        }
      count--;  
        
    }
    
}
int search(int x) {
    int i;
    struct node *tmp;
    for (i = 0; i < count; i++) {
        tmp = head[i];
        while (tmp != NULL) {
            if (tmp->data == x)
                return 1;  
            tmp = tmp->next;
        }
    }
    return 0;  
}

void displayRepresentatives() {
    printf("\nSet Representatives: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", head[i]->data);
    }
    printf("\n");
}

void displaySets() {
    int i, j;
    struct node *temp;
    
    printf("\nDisjoint Sets:\n");
    for (i = 0; i < count; i++) {
        temp = head[i];
        printf("{ ");
        int first = 1;
        while (temp != NULL) {
            if (!first) printf(", ");
            printf("%d", temp->data);
            first = 0;
            temp = temp->next;
        }
        printf(" }\n");
    }
}

int main() {
    int choice, x, y,setSize;
    printf("Enter the size of set (max 20): ");
    scanf("%d", &setSize);

    while (setSize <= 0 || setSize > 20) {
        printf("Please enter a size between 1 and 20: ");
        scanf("%d", &setSize);
    }

    printf("\nEnter %d unique elements:\n", setSize);
    for (int i = 0; i < setSize; ) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        if (search(x)) {
            printf("Element %d already exists in the set. Please enter a unique element.\n", x);
        } else {
            makeSet(x);
            i++;
        }
    }

    do {
        printf("\n1. Display representatives");
        printf("\n2. make Union set");
        printf("\n3. Find ");
        printf("\n4. Display all sets");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayRepresentatives();
                break;

            case 2:
                printf("\nEnter 1st element: ");
                scanf("%d", &x);
                printf("Enter 2nd element: ");
                scanf("%d", &y);
                unionSets(x, y);
                break;

            case 3:
                printf("\nEnter the element to find: ");
                scanf("%d", &x);
                struct node *rep = find(x);
                if (rep == NULL) {
                    printf("\nElement not present.\n");
                } else {
                    printf("\nThe representative of %d is %d\n", x, rep->data);
                }
                break;

            case 4:
                displaySets();
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}
