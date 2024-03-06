#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0,1,1,0},
    {1,0,0,0},
    {1,1,0,1},
    {1,1,1,0}
};

int visited[N] = {0,0,0,0};

void dfs(int i){
    printf("%d\t",i);
    visited[i] = 1;
    for(int j=0;j<N;j++){
        if(graph[i][j]&&!visited[j])
            dfs(j);
    }
}

void main(){
    for(int i=0;i<N;i++){
        if(!visited[i])
            dfs(i);
    }
}