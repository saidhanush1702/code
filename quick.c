#include<stdio.h>

int partition(int arr[],int lb,int ub){
    int i = lb;
    int pivot = arr[lb];
    int j = ub;

    while(j > i){
        while((arr[i] <= pivot)){
            i++;
        }

        while((arr[j] > pivot)){
            j--;
        }

        if(j > i ){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    if(j < i){
        int temp = arr[lb];
        arr[lb] = arr[j];
        arr[j] = temp;

    }
    return j;
}


void quicksort(int arr[],int lb,int ub){
    if(lb < ub){
        int loc = partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int main(){
    int arr[7] = {28,32,45,12,13,42,55};

    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    quicksort(arr,0,6);
    printf("\n");
    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }


}