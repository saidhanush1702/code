#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

void insertend(int data){
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    node* temp = head;
    new->next = NULL;
    if(temp == NULL){
        temp = new;
        head = new;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}

void insertbegin(int data){
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    node* temp = head;
    if(temp == NULL){
        head = new;
    }
    else{
        new->next = temp;
        head = new;
    }
}

void insertpos(int data , int pos){
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    node* temp = head;
    if(temp == NULL){
        temp == new;
        head = temp;
    }
    else{
        
        int po = 1;
        if(pos == 1){
            new->next = temp;
            head = new;

        }
        else {
            while(po != pos-1 ){
                temp = temp->next;
                po = po + 1;
            }
            new->next = temp->next;
            temp->next = new;
        }
    }
}

void deleteend(){
    
    node* temp = head;
    if(temp->next == NULL){
        head == NULL;
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
    }
}

void deletebegin(){
    node* temp = head;
    if(temp->next == NULL){
        head == NULL;
    }
    else{
        head = head->next;
    }
    free(temp);
}

void deletepos(int pos ){
    node* temp = head;
    if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        int po = 1;
        if(pos == 1){
            node* temp1 = temp->next;
            head = temp1;
            free(temp);
        }
        else {
            while(po != pos-1 ){
                temp = temp->next;
                po = po + 1;
            }
            node* temp1 = temp->next;
            if(temp1 -> next == NULL){
                temp -> next = NULL;
            }
            else{
                temp->next = temp->next->next;
            }
            free(temp1);
        }
    }
}

void traversal(){
    printf("\n");
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}


int main(){
    int choice;
    do{
        int data,pos;

        printf("1. insertend\n");
        printf("2. insertbegin\n");
        printf("3. insertpos\n");
        printf("4. deleteend\n");
        printf("5. deletebegin\n");
        printf("6. deletepos\n");
        printf("7. display\n");
        printf("8. exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 : printf("Enter data:");
                    scanf("%d",&data);
                    insertend(data);
                    break;
            
            case 2 : printf("Enter data:");
                    scanf("%d",&data);
                    insertbegin(data);
                    break;

            case 3 : printf("Enter data and position :");
                    scanf("%d%d",&data,&pos);
                    insertpos(data,pos);
                    break;

            case 4 : deleteend();
                    break;

            case 5 : deletebegin();
                    break;

            case 6 : printf("Enter position :");
                    scanf("%d",&pos);
                    deletepos(pos);
                    break;

            case 7 : traversal();
                    break;

            case 8 :printf("Exit"); 
                    break;
        }
    }while(choice != 8);
}