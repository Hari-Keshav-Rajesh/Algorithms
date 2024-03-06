#include <stdio.h>

void Merge(int A[],int len_A,int B[],int len_B,int C[],int len_C){

    int i=0,j=0,k=0;

    while((i<len_B)&&(j<len_C)){
        if(B[i]<C[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
        }
        k++;
    }

    if(j<len_C){
        while(j<len_C){
            A[k] = C[j];
            j++;
            k++;
        }  
    }
    else{
        while(i<len_B){
            A[k] = B[i];
            i++;
            k++;
        }
    }
}

void MergeSort(int arr[],int len){   

    if(len<=1){
        return;
    } 

    int B[len/2];
    int C[len/2];

    for(int i=0;i<len/2;i++){
        B[i] = arr[i];
    }
    MergeSort(B,len/2);

    for(int i=len/2;i<len;i++){
        C[i-len/2] = arr[i];
    }
    MergeSort(C,len-len/2);

    Merge(arr,len,B,len/2,C,len-len/2);

}

void main(){
    int arr[] = {2,4,1,3,6,5};
    int len = 6;
    MergeSort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
}