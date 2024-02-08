#include<stdio.h>
#define max 100

int arr[max];
int f = -1;
int r = -1;

int isEmpty(){
    if(f == -1 && r == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(r == max-1){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(isFull()){
        printf("queue is full");
    }
    else{
        if(isEmpty()){
            f++;
            r++;
            arr[r] = data;
        }
        else{
            r++;
            arr[r] = data;
        }
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Cannot delete");
    }
    else{
        if(f == r){
            f = -1;
            r = -1;

        }
        else{
            f++;
        }
    }
}

void display(){
    if(f == -1){
        printf("queue is empty");
    }
    else{
        for(int i = f ; i <= r ;i++){
            printf("%d ",arr[i]);
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