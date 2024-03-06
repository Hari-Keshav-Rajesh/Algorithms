#include <stdio.h>

void insertionSort(int arr[],int len){
    int i=0,j=0,v=0,temp;

    for(i=1;i<len;i++){
        v = arr[i];
        j = i-1;
        while(j>=0){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j--;
            }
            else{
                break;
            }
        }
    }

    for(i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
}

void main(){
    int arr[] = {1,36,4,8,2};
    int len = 5;
    insertionSort(arr,len);
}