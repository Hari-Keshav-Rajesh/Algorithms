#include <stdio.h>
#include <stdlib.h>

int len = 4;

typedef struct N{
    int val;
    struct N* next;
}node;

node* temp;
node* newn;

int visited[4] = {0,0,0,0};

int bfs_visited[4] = {0,0,0,0};

node* adj[4];

node* queue[4];
int front = 0;
int rear = 0;

void printGraph(node* arr[]){
    for(int i=0;i<len;i++){
        printf("%d",arr[i]->val);
        temp = arr[i]->next;
        while(temp){
            printf("->%d",temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfs(node* t){
    printf("%d\t",t->val);
    visited[t->val] = 1;
    temp = t->next;
    while(temp){
        if(!visited[temp->val]){
            dfs(adj[temp->val]);
        }
        temp = temp->next;
    }
}

void bfs(node* t){
    temp = t;
    while(temp){
        if(!bfs_visited[temp->val]){
            printf("%d\t",temp->val);
            bfs_visited[temp->val] = 1;
            queue[rear++] = adj[temp->val];            
        }
        temp = temp->next;
    }
    if(front<=rear)
        bfs(queue[front++]);
}

void main(){
    int flag;
    for(int i=0;i<len;i++){
        temp = (node*)malloc(sizeof(node));
        temp->val = i;
        temp->next = NULL;
        adj[i] = temp;
        while(1){
            printf("Enter 1 if adjacent vertex to be added to vertex %d:\t",i);
            scanf("%d",&flag);
            if(flag){
                temp = adj[i];
                while(temp->next)
                    temp = temp->next;
                newn = (node*)malloc(sizeof(node));
                temp->next = newn;
                printf("Enter vertex number");
                scanf("%d",&newn->val);
                newn->next = NULL;
            }   
            else
                break;
        }
    }
    printGraph(adj);

    printf("BFS:\n");
    printf("%d\t",adj[0]->val);
    bfs_visited[adj[0]->val] = 1;
    bfs(adj[0]);

    printf("\n");

    printf("DFS:\n");
    for(int i=0;i<len;i++){
        if(!visited[i]){
            dfs(adj[i]);
        }
    }
}