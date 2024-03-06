#include <stdio.h>

int partition(int arr[],int l,int r){
    int i = l;
    int j = r;
    int p = arr[i];
    int temp;

    while(i<j){
        while((arr[i]<=p)&&(i<r)){
            i++;
        }
        while(arr[j]>p&&(j>l)){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;

}

void QuickSort(int arr[],int l,int r){
    
    if(l<r){
    int s = partition(arr,l,r);
    QuickSort(arr,l,s-1);
    QuickSort(arr,s+1,r);
    }
}

void main(){
    int arr[] = {2,4,1,3,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
}