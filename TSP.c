#include <stdio.h>

#define N 4

int minDist = 100;
int totalDist = 0;
int graph[][N] = {
    {0, 4, 2, 5},
    {3, 0, 1, 6},
    {4, 7, 0, 1},
    {4, 7, 9, 0}
};

void TSP(int path[], int visited[], int minPath[], int n) {
    if (n == 0) {
        totalDist = 0;
        for (int i = 0; i < N - 1; i++)
            totalDist += graph[path[i]][path[i + 1]];
        totalDist += graph[path[N - 1]][path[0]]; // Return to the starting city

        if (totalDist < minDist) {
            minDist = totalDist;
            for (int i = 0; i < N; i++)
                minPath[i] = path[i];
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            path[n - 1] = i;
            visited[i] = 1;

            TSP(path, visited, minPath, n - 1);

            visited[i] = 0;
        }
    }
}

int main() {
    int path[N];
    int visited[N];
    int minPath[N];

    for (int i = 0; i < N; i++) {
        path[i] = 0;
        visited[i] = 0;
        minPath[i] = 0;
    }

    TSP(path, visited, minPath, N);

    printf("The minimum distance is %d\n", minDist);
    printf("The minimum distance path is: ");
    for (int i = 0; i < N; i++)
        printf("%d ", minPath[i]+1);
    printf("\n");

    return 0;
}
