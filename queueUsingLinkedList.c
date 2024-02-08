#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

int isEmpty(){
    if(front == NULL && rear == NULL){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if(isEmpty()){
        front = new;
        rear = new;
    }
    else{
        rear->next = new;
        rear = new;
    }

}

void dequeue(){
    if(isEmpty())
    {
        printf("queue is empty");
    }
    else{
        if(front == rear){
            node* temp = front;
            front = NULL;
            rear = NULL;
            free(temp);
        }
        else{
            node* temp = front;
            front = front->next;
            free(temp);
        }
    }
}

void display(){
    if(isEmpty()){
        printf("queue is empty");
    }
    else{
        node* temp = front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int chioce,data;
    do{
        printf("\n1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&chioce);

        switch(chioce){
            case 1 :printf("Enter data : ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            
            case 2 : dequeue();
                    break;

            case 3 : display();
                    break;

            case 4 : printf("Exit");
                    break;
        }
    }while(chioce != 4);
}