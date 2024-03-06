#include <stdio.h>

int opcount = 0;
int selected[6] = {0,0,0,0,0,0};

int knapsack(int n,int i, int v[], int w[], int c){
    opcount++;
    if(i==n){
        return 0;
    }
    int vin, vex;
    if(w[i]<=c){
        selected[i] = 1;
        vin = knapsack(n,i+1,v,w,c-w[i]) + v[i];
        selected[i] = 0;
        vex = knapsack(n,i+1,v,w,c);
        if(vin>vex){
            selected[i] = 1;
            return vin;
        }
        else{
            return vex;
        }
    }
    else{
        return knapsack(n,i+1,v,w,c);
    }

}

void main(){
    int n=10;
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int w[] = {10,8,6,3,4,4,5,3,2,1};
    int c = 10;
    printf("Maximum profit is %d\n",knapsack(n,0,v,w,c));
    printf("Operation ran %d times\n",opcount);
    printf("0/1 list of items are:");
    for(int i=0;i<6;i++){
        printf("%d\t",selected[i]);
    }
}

