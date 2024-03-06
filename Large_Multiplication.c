#include <stdio.h>

#define N 4

int expo(int a){
    int n = 1;
    for(int i=0;i<a;i++)
        n*=10;
    return n;
}

void main(){
    int a = 2500;
    int b = 2405;

    int a1 = a/expo(N/2);
    int b1 = b/expo(N/2);

    int a0 = a%expo(N/2);
    int b0 = b%expo(N/2);

    int c1 = a1*b1;
    int c0 = a0*b0;
    int x = (a1+a0)*(b1+b0);

    int c = c1*expo(N) + (x-c1-c0)*expo(N/2) + c0;

    printf("%d",c);
}