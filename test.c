#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct Edge{
    int src,dst,weight;
}edge;

typedef struct Subset{
    int parent,rank;
}subset;

int find(subset subsets[],int i){
    if(subsets[i].parent!=i){
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[],int x,int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Kruskal(edge edges[]){
    edge MST[V];
    subset subsets[V];

    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    edge temp;
    for(int i=0;i<V-1;i++){
        for(int j=0;j<V-i-1;j++){
            if(edges[j].weight>edges[j+1].weight){
                temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp; 
            }
        }
    }

    int e = 0;
    for(int i=0;i<V-1 && e<V-1;i++){
        int x = find(subsets,edges[i].src);
        int y = find(subsets,edges[i].dst);

        if(x!=y){
            MST[e++] = edges[i];
            Union(subsets,x,y);
        }
    }

    printf("Edge/Weight\n");
    for(int i=0;i<e;i++){
        printf("%d - %d\t%d\n",MST[i].src,MST[i].dst,MST[i].weight);
    }
}

int main() {
    struct Edge edges[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7}, {3, 4, 9}
    };

    Kruskal(edges);

    return 0;
}