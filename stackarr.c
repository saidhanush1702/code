#include<stdio.h>
#include<stdlib.h>
#define n 10

typedef struct stack {
    int arr[n];
    int top;
}stack;

void init(stack* s1){
    s1->top = -1;
}

int isfull(stack* s1){
    return (s1->top == n-1);
}

int isempty(stack* s1){
    return (s1->top == -1);
}

void push(stack* s1,int data){
    if(isfull(s1)){
        printf("Stack is full");
    }
    else{
        s1->top = s1->top + 1;
        s1->arr[s1->top] = data;
    }
}

void pop(stack* s1){
    if(isempty(s1)){
        printf("stack is empty cannot delete.");
    }
    else{
        s1->top--;
    }
}

void display(stack* s1){

    for(int i = 0; i <= s1->top;i++){
        printf("%d ",s1->arr[i]);
    }

}

int main(){

    stack* s1 = (stack*)malloc(sizeof(stack));
    init(s1);

    
        int data,choice;
        do{
            printf("\n1. push\n");
            printf("\n2. pop\n");
            printf("\n3. Display\n");
            printf("\n4. Exit\n");

            printf("Enter choice : ");
            scanf("%d",&choice);

            switch(choice){
                case 1 : printf("Enter data : ");
                        scanf("%d",&data);
                        push(s1,data);
                        break;

                case 2 : pop(s1);
                        break;

                case 3 : display(s1);
                        break;

                case 4 : exit(0);
                        break;
            }  
        }while(choice != 4);





}