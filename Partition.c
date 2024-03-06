#include <stdio.h>

#define len 6

int sum = 0;

int result[] = {0,0,0,0,0,0};

int arr_sum(int arr[]){
    sum = 0;
    for(int i=0;i<len;i++){
        sum+=arr[i];
    }
    return sum;
}

void partition(int arr[]){
    int n = 1<<len;
    for(int i=0;i<n;i++){
        int li[] = {0,0,0,0,0,0};
        int k = 0;
        for(int j=0;j<len;j++){
            if(i&(1<<j)){
                li[k] = arr[j];
                k++;
            }
            if(arr_sum(li)==(arr_sum(arr)/2)){
                for(int i=0;i<len;i++){
                    result[i] = li[i];
                }
                return;
            }
        }
    }
}

void main(){
    int arr[] = {1,2,3,4,5};
    partition(arr);
    for(int i=0;i<len;i++){
        if(result[i]!=0){
            printf("%d\t",result[i]);
        }
    }
}