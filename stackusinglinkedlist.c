#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}


void push(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if(isEmpty()){
        top = new;
    }
    else{
        new->next = top;
        top = new;
    }
}

void pop(){
    if(isEmpty()){
        printf("stack is empty");
    }
    else if(top->next == NULL){
        top = NULL;
    }
    else{
        node* temp =  top;
        top = top->next;
        free(temp);
    }
}

void display(){
    node* temp = top;
    printf("top =");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){
    
    int chioce,data;
    do{
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&chioce);

        switch(chioce){
            case 1 :printf("Enter data : ");
                    scanf("%d",&data);
                    push(data);
                    break;
            
            case 2 : pop();
                    break;

            case 3 : display();
                    break;

            case 4 : printf("Exit");
                    break;
        }
    }while(chioce != 4);

    

}