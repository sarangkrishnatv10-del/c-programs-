#include <stdio.h>

#define INF 9999
#define MAX 100

void floydWarshall(int graph[][MAX], int vertices) {
    int dist[MAX][MAX];
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    printf("\nShortest distances between all pairs:\n");
    printf("    ");
    for (int i = 0; i < vertices; i++) {
        printf("  V%d", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("V%d: ", i);
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%3d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices;
    
    printf("Floyd-Warshall All-Pairs Shortest Path Algorithm\n");
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    int graph[MAX][MAX];
    
    printf("Enter the adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("graph[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    floydWarshall(graph, vertices);
    
    return 0;
}
