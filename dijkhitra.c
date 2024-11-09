#include <stdio.h>
#define INFINITY 999999
int graph[10][10];
int minDistance(int dist[], int sptSet[],int V) {
    int min = INFINITY, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[],int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int src,int V) {
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITY;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet,V);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INFINITY &&
dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist,V);
}

int main() {
printf("Enter number of vertices:");
int V;
    scanf("%d",&V);
    int i,j,n;
printf("\nEnter adjecency matrix of the graph\n");
    for(i=0;i<V;i++)
{
       for(j=0;j<V;j++)
       {
       printf("Is edge exits between %d-%d:",i,j);
        scanf("%d",&graph[i][j]);
       }
}
    printf("enter the source vertex:");
    int s;
    scanf("%d",&s);

    dijkstra(s,V);

    return 0;
}
