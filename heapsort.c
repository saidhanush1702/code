#include<stdio.h>

void heapify(int arr[], int n , int i){
    int lar = i;
    int l = (2*i)+1;
    int r = (2*i)+2;

    if(l <= n-1 && arr[l] > arr[lar]){
        lar = l;
    }

    if(r <= n-1 && arr[r] > arr[lar]){
        lar = r;
    }

    if(lar != i){
        int temp = arr[lar];
        arr[lar] = arr[i];
        arr[i] = temp;
        heapify(arr,n,lar);
    }
}

void heapsort(int arr[],int n){
    for(int i = (n/2)-1 ; i >= 0 ;i--){
        heapify(arr,n,i);
    }

    for(int i = n-1 ; i >= 0 ;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr,i,0);
    }
}

int main(){
    int arr[7] = {28,32,45,12,13,42,55};

    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    heapsort(arr,7);
    printf("\n");
    for(int i = 0 ; i < 7 ; i++){
        printf("%d ",arr[i]);
    }
}