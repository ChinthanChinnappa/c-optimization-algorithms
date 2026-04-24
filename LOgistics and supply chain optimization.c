#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define N 15 

void dijkstra(int graph[N][N], int src) 
{
    int dist[N], visited[N] = {0};
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[src] = 0;

    for (int count = 0; count < N; count++) {
        int u = -1;
        for (int i = 0; i < N; i++) 
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (dist[u] == INF) break;
        visited[u] = 1;

        for (int v = 0; v < N; v++)
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Warehouse %d Shortest Paths:\n", src);
    for (int i = 0; i < N; i++) printf("To %d: %d\n", i, dist[i]);
}

int main() {
    int graph[N][N] = {
        {0, 10, 0, 30, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50, 0, 20, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {30, 0, 20, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {100, 0, 10, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 15, 0, 0, 20, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 25, 10, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 15, 25, 0, 5, 10, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 5, 0, 20, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 10, 20, 0, 30, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 20, 0, 0, 0, 30, 0, 5, 25, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 30, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 10, 0, 15, 20},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 15, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 5, 0}
    };

    for (int i = 0; i < 5; i++) dijkstra(graph, i);
    return 0;
}
