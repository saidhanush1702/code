#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

void insertend(int data){
    node* temp = head;
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if(temp == NULL){
        new->next = new;
        head = new;
    }
    else{
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
    }
}

void insertbegin(int data){
    node* temp = head;
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if(temp == NULL){
        new->next = new;
        head = new;
    }
    else{
        new->next = temp;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new;
        head = new;
    }
}

void insertpos(int data,int pos){
    node* temp = head;
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if(temp == NULL){
        new->next = new;
        head = new;
    }
    else{
        int po = 1;
        if(pos == 1){
            new->next = temp;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = new;
            head = new;
        }
        else{
            while(po != pos-1){
                temp = temp->next;
                po = po+1;
            }
            new->next = temp->next;
            temp->next = new;

        }
    }
}

void deleteend(){
    node* temp = head;
    if(temp->next == temp){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->next->next != head){
            temp = temp->next;
        }
        node* fr = temp->next;
        temp->next = head;
        free(fr);
    }

}

void deletebegin(){
    node* temp = head;
    if(temp->next == temp){
        head = NULL;
        free(temp);
    }
    else{
        node* fr = temp; 
        head = temp->next;
        while(temp -> next != head){
            temp = temp->next;
        }
        temp->next = head;
        free(fr);
    }
}

void deletepos(int pos){
    node* temp = head;
    if(temp->next == temp){
        head = NULL;
        free(temp);
    }
    else{
        int po = 1;
        if(pos == 1){
            node* fr = temp; 
            head = temp->next;
            while(temp -> next != head){
                temp = temp->next;
            }
            temp->next = head;
            free(fr);

        }
        else{
            while(po != pos - 1){
                temp = temp->next;
                po = po +1;
            }
            if(temp->next->next == head){
                node* fr = temp->next;
                temp->next = head;
                free(fr);
            }
            else{
                node* fr = temp->next;
                temp->next = temp->next->next;
                free(fr);
            }
        }
    }
}

void display(){
    node* temp = head;
    do{
        printf("%d ->",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("head");
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
        printf("7. Display\n");
        printf("8. Exit\n");
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

            case 7 : display();
                    break;

            case 8 :printf("Exit"); 
                    break;
        }
    }while(choice != 9);
}