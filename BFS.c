#include <stdio.h>

int adj[100][100] = {
        {1,0,1,1,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {1,0,0,0,1},
        {1,1,0,0,0}
};
int visited[100] = {0,0,0,0,0};
int n = 5;

int queue[100] = {0,0,0,0,0};
int front = 0;
int rear = 0;


void bfs(int i){
    for(int j=0;j<n;j++){
        if(adj[i][j]&&!visited[j]){
            visited[j] = 1;
            queue[rear++] = j;
            printf("%d\t",j);
        }
    }
    if(front<=rear){
        bfs(queue[front++]);
    }
}

void main(){
    printf("0\t");
    visited[0] = 1;
    bfs(0);
}