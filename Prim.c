#include <stdio.h>
#include <stdbool.h>
#define V 5
#define INT_MAX 99999

int minKey(int key[],int MST[]){
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(key[v]<min&&MST[v]==false){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    int MST[V];

    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        MST[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;

    for(int i=0;i<V-1;i++){
        int u = minKey(key,MST);
        MST[u] = true;

        for(int v=0;v<V;v++){
            if(graph[u][v]&&MST[v]==false&&graph[u][v]<key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }

    }

    printMST(parent,graph);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    
    primMST(graph);

    return 0;
}
