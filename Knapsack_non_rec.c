#include <stdio.h>
#define len 5
int result[len];
#define max_weight 10
int max_profit = 0;

int sum(int arr[]){
    int sum = 0;
    for(int i=0;i<len;i++){
        sum+=arr[i];
    }
    return sum;
}

void knapsack(int val[],int weight[]){
    int n = 1 << len;

    for(int i=0;i<n;i++){
        int k=0;
        int test_val[] = {0,0,0,0,0};
        int test_weight[] = {0,0,0,0,0};
        for(int j=0;j<len;j++){
            if(i&(1<<j)){
                test_val[k] = val[j];
                test_weight[k] = weight[j];
                k++;
            }
        }
        if( (sum(test_val)>max_profit) & (sum(test_weight)<=max_weight) ){
            max_profit = sum(test_val);
            int j = 0;
            for(int x=0;x<len;x++){
                if(test_val[x]!=0){
                    result[j] = test_val[x];
                    j++;
                }
            }
        }
    }

}

void main(){
    int val[] = {2,3,4,5,6};
    int weight[] = {1,3,5,6,7};
    knapsack(val,weight);
    printf("%d\n",max_profit);
    printf("Values to be chosen are:\n");
    int length = sizeof(result)/sizeof(result[0]);
    for(int i=0;i<length;i++){
        if(result[i]==0){
            break;
        }
        printf("%d\t",result[i]);
    }
}