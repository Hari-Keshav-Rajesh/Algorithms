#include <stdio.h>

#define N 4

int minCost = 100;

int totalCost = 0;

int cost[][N] = {
    {1,4,2,5},
    {3,2,1,6},
    {4,7,2,1},
    {4,7,9,2}
};

void assignJobs(int worker[],int assigned[],int minAssignment[],int n){

    if(n==0){
        totalCost = 0;
        for(int i=0;i<N;i++)
            totalCost += cost[i][worker[i]];
        printf("%d\n",totalCost);
        if(totalCost<minCost){
            minCost = totalCost;
            for(int i=0;i<N;i++)
                minAssignment[i] = worker[i];
        }
        return;
    }

    for(int i=0;i<N;i++){
        if(!assigned[i]){
            worker[n-1] = i;
            assigned[i] = 1;

            assignJobs(worker,assigned,minAssignment,n-1);

            assigned[i] = 0;
        }
    }

}

void main(){
    int worker[N];
    int assigned[N];
    int minAssignment[N];

    for(int i=0;i<N;i++){
        worker[i] = 0;
        assigned[i] = 0;
        minAssignment[i] = 0;
    }

    assignJobs(worker,assigned,minAssignment,N);
    
    printf("The minimum cost is %d\n",minCost);
    for(int i=0;i<N;i++)
        printf("Worker %d assigned to job %d\n",i+1,minAssignment[i]+1);
}