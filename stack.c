#include<stdio.h>
#define max 100

int arr[max];
int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(top == max-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("stack is full ");
    }
    else{
        top++;
        arr[top] = data;
    }
}

void pop(){
    if(isEmpty()){
        printf("stack is empty");
    }
    else{
        top--;
    }

}

void display(){
    for(int i = top ; i >=0 ; i--){
        printf("%d ",arr[i]);
    }

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