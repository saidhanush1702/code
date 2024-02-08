#include<stdio.h>

void merge(int arr[],int lb, int mid,int ub){
    int i = lb;
    int k = lb;
    int j = mid + 1;

    int b[ub+1];

    while(i <= mid && j <= ub){
        if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        }
        else {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    if(i > mid){
        while(j <= ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for(int i = lb ; i <= ub ; i++){
        arr[i] = b[i];
    }
}

void mergesort(int arr[],int lb,int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        printf("%d",mid);
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    int arr[7] = {28,32,45,12,13,42,55};

    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergesort(arr,0,6);
    printf("\n");
    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }
}