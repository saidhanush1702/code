#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* head = NULL;

void insertend(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    node* temp = head;
    if(temp == NULL)
    {
        head = new;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
    }

}

void insertbegin(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    node* temp = head;
    if(temp == NULL)
    {
        head = new;
    }
    else{
        new->next = temp;
        temp->prev = new;
        head = new;
    }

}

void insertpos(int data,int pos){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    node* temp = head;
    if(temp == NULL){
        head = new;
    }
    else{
        int po = 1;
        if(pos == 1){
            new->next = temp;
            temp->prev = new;
            head = new;
        }
        else{
            while(po != pos-1){
                temp = temp->next;
                po = po+1;
            }
            new->next = temp->next;
            temp->next->prev = new;
            new->prev = temp;
            temp->next = new;
        }
    }
}

void deleteend(){
    node* temp = head;
    if(temp->next == NULL){
        head = NULL;
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
        head = NULL;
    }
    else{
        node* temp1 = temp->next;
        head = temp1;
        free(temp);
    }
}

void deletepos(int pos){
    node* temp = head;
    if(temp->next == NULL){
        head = NULL;
    }
    else{
        if(pos == 1){
            head = temp->next;
            free(temp);
        }
        else{
            int po = 1;
            while(po != pos-1){
                temp = temp->next;
                po = po + 1;
            }
            
            node* fr = temp->next;
            if(temp->next->next == NULL)
            {
                temp->next = NULL;
            }
            else{
                    
                temp->next = temp->next->next;
                temp->next->next->prev = temp;
            }
            free(fr);
        }
    }
}

void displayFE(){
    node* temp = head;
    printf("NULL <->");
    while(temp != NULL){
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void displayEF(){
    node* temp = head;
    printf("NULL <->");
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d <->",temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){
    int choice;
    do{
        int data,pos;

        printf("\n 1. Insertend\n");
        printf("2. Insertbegin\n");
        printf("3. Insertpos\n");
        printf("4. Deleteend\n");
        printf("5. Deletebegin\n");
        printf("6. Deletepos\n");
        printf("7. DisplayStartToEnd\n");
        printf("8. DisplayEndToStart\n");
        printf("9. Exit\n");
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
                    scanf("%d",&data);
                    scanf("%d",&pos);
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

            case 7 : displayFE();
                    break;

            case 8 : displayEF();
                    break;

            case 9 :printf("Exit"); 
                    break;
        }
    }while(choice != 9);
    


}